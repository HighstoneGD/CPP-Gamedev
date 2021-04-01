#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"

int main() {
    DynamicArray array;
    constructor(&array);
    push_back(&array, 43);
    push_back(&array, -7);
    push_back(&array, 0);
    push_back(&array, 3);
    DataType res;
    get_element(&array, 1, &res);
    printf("%d\n%d\n", res, array.size);
    destructor(&array);
    pop_back(&array);
    printf("%d", array.size);
    return 0;
}