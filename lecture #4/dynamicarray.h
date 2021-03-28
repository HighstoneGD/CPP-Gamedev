typedef int DataType;

const unsigned DEFAULT_CAPACITY = 16;

typedef struct DynamicArray {
    unsigned size;
    unsigned capacity;
    DataType *buf;
} DynamicArray;

typedef enum ErrorType {
    SUCCESS,
    SIZE_LIMIT,
    NULL_POINTER,
    OUT_OF_BOUNDS,
    MEMORY_ALLOC_ERROR
} ErrorType;

ErrorType default_constructor(DynamicArray *array);

ErrorType constructor(DynamicArray *array, unsigned size, DataType *default_array);

ErrorType destructor(DynamicArray *array);

ErrorType push_back(DynamicArray *array, DataType elem);

ErrorType pop_back(DynamicArray *array);

ErrorType get_element(DynamicArray *array, unsigned index, DataType *result);