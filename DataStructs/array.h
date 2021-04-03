#include "errortype.h"

#define CAPACITY 40
typedef int DataType;

typedef struct Array {
    unsigned size;
    DataType buf[CAPACITY];
} Array;

ErrorType array_constructor_default(Array * array);

ErrorType array_constructor(Array * array, unsigned size, DataType * default_buf);

ErrorType array_destructor(Array * array);

ErrorType array_push_back(Array * array, DataType num);

ErrorType array_pop_back(Array * array);

ErrorType array_insert(Array * array, unsigned index, DataType elem);

ErrorType array_delete_element(Array * array, unsigned index);

ErrorType array_clear(Array * array);

ErrorType array_assign(Array * array, Array array2);

ErrorType array_get_element(Array * array, unsigned index, DataType * result);