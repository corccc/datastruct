/*
 * Copyright (C) kong
 */

#ifndef DATASTRUCT_ARRAY_H
#define DATASTRUCT_ARRAY_H

#include <stdlib.h>

typedef struct {
    void           *elts;     /* 实际数据 */
    size_t          nelts;    /* 已存放数量 */
    size_t          size;     /* 每个元素大小 */
    size_t          nalloc;   /* 分配的大小 */
} array_t;


/* 初始化数组 */
array_t *array_init(size_t n, size_t size);

/* 销毁数组 */
void array_destory(const array_t *array);

/* 数组中添加元素 */
void *array_push(array_t *array, void *elts);

/* 查找某位置对应元素 */
void *array_value(const array_t *array, size_t index);

/* 打印数组中的元素 */
void array_print(const array_t *array);

#endif //DATASTRUCT_ARRAY_H
