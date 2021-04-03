#include "errortype.h"

#define DEFAULT_CAPACITY 16

typedef int DataType;

typedef struct DynamicArray {
    unsigned size;
    unsigned capacity;
    DataType *buf;
} DynamicArray;

ErrorType constructor(DynamicArray *array);

ErrorType destructor(DynamicArray *array);

ErrorType push_back(DynamicArray *array, DataType elem);

ErrorType pop_back(DynamicArray *array);

ErrorType get_element(DynamicArray *array, unsigned index, DataType *result);