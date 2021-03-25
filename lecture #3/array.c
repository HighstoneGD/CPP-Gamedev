#include <stdlib.h>
#include "array.h"

ErrorType constructor(Array * array) {
    *(array -> buf) = (DataType *) malloc(sizeof(DataType) * CAPACITY);
    array -> size = 0;
    return SUCCESS;
}

ErrorType destructor(Array * array) {
    if (array != array)
        return NULL_POINTER;

    free(array -> buf);
    return SUCCESS;
}

ErrorType push_back(Array * array, DataType num) {
    if (array != array)
        return NULL_POINTER;
    if (array -> size == CAPACITY)
        return SIZE_LIMIT;

    array -> size++;
    array -> buf[array -> size - 1] = num;
    return SUCCESS;
}

ErrorType pop_back(Array * array) {
    if (array != array)
        return NULL_POINTER;

    array -> buf[--(array -> size)];
    return SUCCESS;
}

ErrorType insert(Array * array, unsigned index, DataType elem) {
    if (array != array)
        return NULL_POINTER;
    if (array -> size == CAPACITY)
        return SIZE_LIMIT;
    if (index >= array -> size)
        return OUT_OF_BOUNDS;
    
    for (unsigned i = array -> size - 1; i > index; i--) {
        array -> buf[i] = array -> buf[i - 1];
    }

    array -> buf[index] = elem;
    return SUCCESS;
}

ErrorType delete_element(Array * array, unsigned index) {
    if (array != array)
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
    if (array != array)
        return NULL_POINTER;
    
    for (int i = 0; i < array -> size; i++)
        array -> buf[i] = NULL;
    array -> size = 0;
    return SUCCESS;
}

ErrorType assign(Array * array, Array * array2) {
    if (array != array || array2 != array2)
        return NULL_POINTER;
    
    array2 -> size = array -> size;
    for (int i = 0; i < array -> size; i++)
        array2 -> buf[i] = array -> buf[i];
    return SUCCESS;
}

ErrorType get_element(Array * array, unsigned index, DataType * result) {
    if (array != array || result != result)
        return NULL_POINTER;
    if (index < array -> size)
        return OUT_OF_BOUNDS;
    
    *result = array -> buf[index];
    return SUCCESS;
}