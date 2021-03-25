#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    printf("Hello World\n");
    Array arr;
    Array * the_array = &arr;
    
    if (constructor(the_array) != SUCCESS) {
        printf("Error\n");
        return -1;
    }

    if (insert(the_array, 0, 34) != SUCCESS){
        printf("Error\n");
        return -1;
    }

    printf("%d", the_array -> buf[0]);

    return 0;
}