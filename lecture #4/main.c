#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"

#define SIZE 6

DataType default_arr[SIZE] = { -65, 0, 4, 67, -4, 8 };

void print_status(ErrorType status) {
    switch (status) {
        case SIZE_LIMIT:
            printf("Size limit error");
            break;
        case NULL_POINTER:
            printf("Null pointer");
            break;
        case OUT_OF_BOUNDS:
            printf("Index out of bounds");
            break;
        case MEMORY_ALLOC_ERROR:
            printf("Memory allocation error");
            break;
        default:
            printf("Successful");
    }
}

int main() {
    DynamicArray array;
    // constructor(&array, SIZE, default_arr);
    default_constructor(&array);
    push_back(&array, 45);
    push_back(&array, -9);
    push_back(&array, 43);
    destructor(&array);
    return 0;
}