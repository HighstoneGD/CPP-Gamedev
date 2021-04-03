#include <stdlib.h>
#include "dynamicarray.h"

ErrorType constructor(DynamicArray *array) {
    if (!array)
        return NULL_POINTER;
    
    array -> capacity = DEFAULT_CAPACITY;
    array -> buf = malloc(sizeof(DataType) * array -> capacity);
    array -> size = 0;
    return SUCCESS;
}

ErrorType destructor(DynamicArray *array) {
    if (!array)
        return NULL_POINTER;
    
    free(array -> buf);
    return SUCCESS;
}

ErrorType push_back(DynamicArray *array, DataType elem) {
    if (!array)
        return NULL_POINTER;
    
    if (array -> size == array -> capacity) {
        array -> capacity *= 2;
        DataType *new_buf = realloc(array -> buf, sizeof(DataType) * (array -> capacity));
        if (!new_buf)
            return MEMORY_ALLOC_ERROR;
        array -> buf = new_buf;
    }

    array -> buf[array -> size] = elem;
    array -> size++;
    return SUCCESS;
}

ErrorType pop_back(DynamicArray *array) {
    if (!array)
        return NULL_POINTER;
    if (array -> size == 0)
        return SIZE_LIMIT;
    
    array -> size--;
    return SUCCESS;
}

ErrorType get_element(DynamicArray *array, unsigned index, DataType *result) {
    if (!array || !result)
        return NULL_POINTER;
    if (array -> size <= index)
        return OUT_OF_BOUNDS;
    
    *result = array -> buf[index];
    return SUCCESS;
}