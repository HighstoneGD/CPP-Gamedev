#include <stdlib.h>
#include "dynamicarray.h"

ErrorType default_constructor(DynamicArray *array) {
    if (!array)
        return NULL_POINTER;
    
    array -> buf = NULL;
    array -> size = 0;
    array -> capacity = DEFAULT_CAPACITY;
}

ErrorType constructor(DynamicArray *array, unsigned size, DataType *default_array) {
    if (!array || !default_array)
        return NULL_POINTER;
    
    array -> size = size;
    array -> buf = malloc(sizeof(DataType) * size);
    
    for (int i = 0; i < size; i++)
        array -> buf[i] = default_array[i];
    
    return SUCCESS;
}

ErrorType destructor(DynamicArray *array) {
    if (!array)
        return NULL_POINTER;
    
    free(array -> buf);
    //array -> size = 0;

    return SUCCESS;
}

ErrorType push_back(DynamicArray *array, DataType elem) {
    if (!array)
        return NULL_POINTER;
    
    DataType *new_buf = realloc(array -> buf, sizeof(DataType) * array -> size + 1);

    if (!new_buf) {
        free(new_buf);
        return MEMORY_ALLOC_ERROR;
    } else {
        array -> buf = new_buf;
        array -> buf[array -> size] = elem;
        array -> size++;
        return SUCCESS;
    }
}

ErrorType pop_back(DynamicArray *array) {
    if (!array)
        return NULL_POINTER;
    
    DataType *new_buf = realloc(array -> buf, sizeof(DataType) * array -> size - 1);

    if (!new_buf) {
        free(new_buf);
        return MEMORY_ALLOC_ERROR;
    } else {
        array -> buf = new_buf;
        array -> size--;
        return SUCCESS;
    }
}

ErrorType get_element(DynamicArray *array, unsigned index, DataType *result) {
    if (!array || !result)
        return NULL_POINTER;
    if (array -> size <= index)
        return OUT_OF_BOUNDS;
    
    *result = array -> buf[index];
    return SUCCESS;
}