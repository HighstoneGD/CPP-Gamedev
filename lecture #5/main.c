#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef enum ErrorType {
    SUCCESS,
    SIZE_LIMIT,
    NULL_POINTER,
    OUT_OF_BOUNDS,
    MEMORY_ALLOC_ERROR
} ErrorType;

typedef struct ListNode {
    DataType value;
    ListNode *next;
} ListNode;

typedef struct List {
    ListNode *head;
} List;

ErrorType constructor(List *list) {
    if (!list)
        return NULL_POINTER;

    list -> head = NULL;
    return SUCCESS;
}

ErrorType push_front(List *list, DataType elem) {
    if (!list)
        return NULL_POINTER;
    
    ListNode *tmp = (ListNode *) malloc(sizeof(ListNode));
    tmp -> value = elem;
    tmp -> next = list -> head;
    list -> head = tmp;
    return SUCCESS;
}

ErrorType pop_front(List *list) {
    if (!list)
        return NULL_POINTER;
    if (!list -> head)
        return SIZE_LIMIT;
    
    ListNode *tmp = list -> head;
    list -> head = tmp -> next;
    free(tmp);
    return SUCCESS;
}

ErrorType destructor(List *list) {
    if (!list)
        return NULL_POINTER;
    
    ListNode *tmp;
    while (!list -> head) {
        tmp = list -> head -> next;
        free(list -> head);
        list -> head = tmp;
    }
}

ErrorType insert_after(List *list, ListNode *node, DataType element) {
    if (!list || !node)
        return NULL_POINTER;
    
    ListNode *tmp = (ListNode *) malloc(sizeof(ListNode));
    tmp -> next = node -> next;
    tmp -> value = element;
    node -> next = tmp;
    return SUCCESS;
}

ErrorType get_element_at(List *list, unsigned index, ListNode *result) {
    if (!list)
        return NULL_POINTER;
    

}

int main() {
    
    

    return 0;
}