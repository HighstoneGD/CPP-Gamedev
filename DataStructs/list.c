#include <stdlib.h>
#include "list.h"

ErrorType list_constructor(List *list) {
    if (!list)
        return NULL_POINTER;

    list -> head = NULL;
    list -> tail = NULL;
    return SUCCESS;
}

ErrorType list_destructor(List *list) {
    if (!list)
        return NULL_POINTER;
    
    ListNode *tmp;
    while (!list -> head) {
        tmp = list -> head -> next;
        free(list -> head);
        list -> head = tmp;
    }
    return SUCCESS;
}

ErrorType list_push_front(List *list, DataType elem) {
    if (!list)
        return NULL_POINTER;
    
    ListNode *tmp = (ListNode *) malloc(sizeof(ListNode));
    tmp -> value = elem;
    tmp -> next = list -> head;
    tmp -> prev = NULL;
    list -> head = tmp;

    if (!list -> head -> next)
        list -> tail = tmp;
    return SUCCESS;
}

ErrorType list_pop_front(List *list) {
    if (!list)
        return NULL_POINTER;
    if (!list -> head)
        return SIZE_LIMIT;
    
    ListNode *tmp = list -> head;
    list -> head = tmp -> next;
    if (list -> head)
        list -> head -> prev = NULL;
    free(tmp);
    return SUCCESS;
}

ErrorType list_insert_after(List *list, ListNode *node, DataType elem) {
    if (!list || !node)
        return NULL_POINTER;
    
    ListNode *tmp = (ListNode *) malloc(sizeof(ListNode));
    tmp -> next = node -> next;
    tmp -> prev = node;
    tmp -> value = elem;
    node -> next = tmp;
    return SUCCESS;
}

ErrorType list_erase_after(List *list, ListNode *node) {
    if (!list || !node)
        return NULL_POINTER;
    if (!node -> next)
        return SIZE_LIMIT;

    ListNode *tmp = node -> next;
    node -> next = tmp -> next;
    tmp -> next -> prev = node;
    free(tmp);
    return SUCCESS; 
}

ErrorType list_push_back(List *list, DataType elem) {
    if (!list)
        return NULL_POINTER;
    
    ListNode *tmp = (ListNode *) malloc(sizeof(ListNode));
    tmp -> value = elem;
    tmp -> prev = list -> tail;
    tmp -> next = NULL;
    list -> tail = tmp;

    if (!list -> tail -> prev)
        list -> head = tmp;
    return SUCCESS;
}

ErrorType list_pop_back(List *list) {
    if (!list)
        return NULL_POINTER;
    if (!list -> tail)
        return SIZE_LIMIT;
    
    ListNode *tmp = list -> tail;
    list -> tail = tmp -> prev;
    if (list -> tail)
        list -> tail -> next = NULL;
    free(tmp);
    return SUCCESS;
}

ErrorType list_insert(List *list, unsigned index, DataType elem);

ErrorType list_erase(List *list, unsigned index);