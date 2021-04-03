#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"
#include "list.h"

int main() {
    // DynamicArray array;
    // constructor(&array);
    // push_back(&array, -7);
    // DataType res;
    // printf("%d", get_element(&array, 0, &res));
    // push_back(&array, 0);
    // push_back(&array, 3);
    // printf("%d\n%d\n", res, array.size);
    // destructor(&array);
    // pop_back(&array);
    // printf("%d", array.size);

    List list;
    list_constructor(&list);
    list_push_front(&list, 32);
    list_push_front(&list, 76);
    list_push_front(&list, 5);

    ListNode *tmp = list.head;
    int counter = 0;
    while (tmp) {
        printf("%d: %d\n", counter + 1, tmp -> value);
        tmp = tmp -> next;
        counter++;
    }

    list_pop_front(&list);

    tmp = list.head;
    counter = 0;
    while (tmp) {
        printf("%d: %d\n", counter + 1, tmp -> value);
        tmp = tmp -> next;
        counter++;
    }

    list_destructor(&list);

    return 0;
}