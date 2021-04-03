#include <stdlib.h>
#include <stdio.h>
#include "array.h"

ErrorType array_constructor_default(Array * array) {
    if (!array)
        return NULL_POINTER;

    array -> size = 0;
    return SUCCESS;
}

ErrorType array_constructor(Array * array, unsigned size, DataType * default_buf) {
    if (!array)
        return NULL_POINTER;
    if (size > CAPACITY)
        return SIZE_LIMIT;
    if (!default_buf)
        return NULL_POINTER;
    
    array -> size = size;
    for (unsigned i = 0; i < size; i++)
        array -> buf[i] = default_buf[i];

    return SUCCESS;
}

ErrorType array_destructor(Array * array) {
    if (!array)
        return NULL_POINTER;

    return SUCCESS;
}

ErrorType array_push_back(Array * array, DataType elem) {
    if (!array)
        return NULL_POINTER;
    if (array -> size == CAPACITY)
        return SIZE_LIMIT;

    array -> size++;
    array -> buf[array -> size - 1] = elem;
    return SUCCESS;
}

ErrorType array_pop_back(Array * array) {
    if (!array)
        return NULL_POINTER;
    if (array -> size == 0)
        return SIZE_LIMIT;

    array -> size--;
    return SUCCESS;
}

ErrorType array_insert(Array * array, unsigned index, DataType elem) {
    if (!array)
        return NULL_POINTER;
    if (array -> size == CAPACITY)
        return SIZE_LIMIT;
    if (index >= array -> size)
        return OUT_OF_BOUNDS;
    
    array -> size++;
    for (unsigned i = array -> size - 1; i > index; i--) {
        array -> buf[i] = array -> buf[i - 1];
    }

    array -> buf[index] = elem;
    return SUCCESS;
}

ErrorType array_delete_element(Array * array, unsigned index) {
    if (!array)
        return NULL_POINTER;
    if (array -> size == 0)
        return SIZE_LIMIT;
    if (index >= array -> size)
        return OUT_OF_BOUNDS;
    
    array -> size--;
    for (unsigned i = index; i < array -> size; i++)
        array -> buf[i] = array -> buf[i + 1];
    return SUCCESS;
}

ErrorType array_clear(Array * array) {
    if (!array)
        return NULL_POINTER;
    
    array -> size = 0;
    return SUCCESS;
}

ErrorType array_assign(Array * array, Array array2) {
    if (!array)
        return NULL_POINTER;
    
    array -> size = array2.size;
    for (unsigned i = 0; i < array2.size; i++)
        array -> buf[i] = array2.buf[i];
    return SUCCESS;
}

ErrorType array_get_element(Array * array, unsigned index, DataType * result) {
    if (!array || !result)
        return NULL_POINTER;
    if (index >= array -> size)
        return OUT_OF_BOUNDS;

    *result = array -> buf[index];
    return SUCCESS;
}