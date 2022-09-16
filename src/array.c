/*
 * Copyright (C) kong
 */

#include "array.h"
#include <string.h>
#include <stdio.h>

array_t *
array_init(size_t n, size_t size)
{
    array_t *a;

    a = calloc(sizeof(array_t), sizeof(char));
    if (a == NULL) {
        return NULL;
    }

    a->nelts = 0;
    a->size  = size;
    a->nalloc = n;

    a->elts = calloc(n, size);
    if (a->elts == NULL) {
        return NULL;
    }

    return a;
}

void
array_destory(const array_t *array)
{
    if (array && array->elts) {
        free(array->elts);
        free(array);
    } else if (array && !array->elts) {
        free(array);
    }
}

void *
array_push(array_t *array, void *elts)
{
    size_t offset = array->nelts * array->size;
    if (array->nelts == array->nalloc) {

        void *address = calloc(array->nalloc * 2, array->size);
        if (address == NULL) {
            return NULL;
        }

        memcpy(address, array->elts, offset);
        memcpy(address + offset, elts, array->size);
        free(array->elts);
        array->elts  = address;
        array->nalloc = 2 * array->nalloc;
        array->nelts ++;
    } else {
        memcpy(array->elts + offset, elts, array->size);
        array->nelts ++;
    }
    return array->nelts;
}

void *
array_value(const array_t *array, size_t index)
{
    if (index > array->nelts) {
        return NULL;
    }
    uint8_t *val = calloc(1, array->size + 1);
    memcpy(val, array->elts + index * array->size, array->size);
    return val;
}

void
array_print(const array_t *array)
{
    int i;

    for (i = 0; i < array->nelts; i++) {

        for (int j = 0; j < array->size; ++j) {
            unsigned  char *p = array->elts + i * array->size + j;
            printf("%02x", p[0]);
        }

        printf("\n");
    }

}