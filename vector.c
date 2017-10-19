//
//  vector.c
//  DataStructures
//
//  Created by Viviana Uscocovich-Mena on 10/18/17.
//  Copyright © 2017 Viviana Uscocovich-Mena. All rights reserved.
//

#include "vector.h"
#include <stdlib.h>

typedef struct vector {
    unsigned int size;
    unsigned int capacity;
    void **array;
} vector_t;

vector_t *vector_create(unsigned int capacity) {
    if (capacity == 0) {
        return 0;
    }

    vector_t *vector = malloc(sizeof(vector_t));
    if (!vector) {
        return 0;
    }

    vector->size = 0;
    vector->capacity = capacity;

    vector->array = malloc(sizeof(void *) * capacity);
    if (!vector->array) {
        free(vector);
        return 0;
    }

    return vector;
}

static int resize(vector_t *vector, unsigned int new_size) {
    vector->array = (void **)realloc(vector->array, sizeof(void *) * new_size);
    if (!vector->array) return 0;
    vector->capacity = new_size;
    return 1;
}

void vector_append(vector_t *vector, void *data) {
    if (vector->size == vector->capacity) {
        if (!resize(vector, vector->capacity * 2)) {
            return;
        }
    }

    vector->array[vector->size++] = data;
}

void *vector_get_item_at(vector_t *vector, unsigned int index) {
    return vector->array[index];
}

unsigned int vector_size(vector_t *vector) {
    return vector->size;
}

