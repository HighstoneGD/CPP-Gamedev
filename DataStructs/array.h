#define CAPACITY 40
typedef int DataType;

typedef struct Array {
    unsigned size;
    DataType buf[CAPACITY];
} Array;

typedef enum ErrorType {
    SUCCESS,
    SIZE_LIMIT,
    NULL_POINTER,
    OUT_OF_BOUNDS
} ErrorType;

ErrorType constructor_default(Array * array);

ErrorType constructor(Array * array, unsigned size, DataType * default_buf);

ErrorType destructor(Array * array);

ErrorType push_back(Array * array, DataType num);

ErrorType pop_back(Array * array);

ErrorType insert(Array * array, unsigned index, DataType elem);

ErrorType delete_element(Array * array, unsigned index);

ErrorType clear(Array * array);

ErrorType assign(Array * array, Array array2);

ErrorType get_element(Array * array, unsigned index, DataType * result);