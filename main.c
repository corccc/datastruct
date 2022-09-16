/*
 * Copyright (C) kong
 */
#include <stdio.h>
#include <string.h>
#include "array.h"

int main(int argc, char **argv) {
    printf("stdio.h");
    array_t *a = array_init(5, sizeof(int));

    for (int i = 0; i < 10; ++i) {
        array_push(a, &i);
    }
    printf("array nelts: %d\n", a->nelts);

    unsigned char *value = array_value(a, 7);
    for (int i = 0; i < 4; ++i) {
        printf("%02x", value[i]);
    }
}
 
 