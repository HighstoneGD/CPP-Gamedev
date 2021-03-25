#include <stdlib.h>
#include <stdio.h>
#include "array.h"

ErrorType constructor_default(Array * array) {
    array -> size = 0;
    return SUCCESS;
}

ErrorType constructor(Array * array, unsigned size, DataType * default_buf) {
    if (size > CAPACITY)
        return SIZE_LIMIT;
    if (!default_buf)
        return NULL_POINTER;
    
    array -> size = size;
    for (int i = 0; i < size; i++)
        array -> buf[i] = default_buf[i];

    return SUCCESS;
}

ErrorType destructor(Array * array) {
    if (!array)
        return NULL_POINTER;

    return SUCCESS;
}

ErrorType push_back(Array * array, DataType num) {
    if (!array)
        return NULL_POINTER;
    if (array -> size == CAPACITY)
        return SIZE_LIMIT;

    array -> size++;
    array -> buf[array -> size - 1] = num;
    return SUCCESS;
}

ErrorType pop_back(Array * array) {
    if (!array)
        return NULL_POINTER;

    array -> buf[--(array -> size)];
    return SUCCESS;
}

ErrorType insert(Array * array, unsigned index, DataType elem) {
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

ErrorType delete_element(Array * array, unsigned index) {
    if (!array)
        return NULL_POINTER;
    if (array -> size == 0)
        return SIZE_LIMIT;
    if (index >= array -> size)
        return OUT_OF_BOUNDS;
    
    array -> size--;
    for (int i = index; i < array -> size; i++)
        array -> buf[i] = array -> buf[i + 1];
    return SUCCESS;
}

ErrorType clear(Array * array) {
    if (!array)
        return NULL_POINTER;
    
    for (int i = 0; i < array -> size; i++)
        array -> buf[i] = (DataType) NULL;
    array -> size = 0;
    return SUCCESS;
}

ErrorType assign(Array * array, Array * array2) {
    if (!array || !array2)
        return NULL_POINTER;
    
    array2 -> size = array -> size;
    for (int i = 0; i < array -> size; i++)
        array2 -> buf[i] = array -> buf[i];
    return SUCCESS;
}

ErrorType get_element(Array * array, unsigned index, DataType * result) {
    if (!array || !result)
        return NULL_POINTER;
    if (index >= array -> size)
        return OUT_OF_BOUNDS;

    *result = array -> buf[index];
    return SUCCESS;
}