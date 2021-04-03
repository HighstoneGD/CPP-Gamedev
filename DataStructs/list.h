#include "errortype.h"

typedef int DataType;

typedef struct ListNode {
    DataType value;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

typedef struct List {
    ListNode *head;
    ListNode *tail;
} List;

ErrorType list_constructor(List *list);

ErrorType list_destructor(List *list);

ErrorType list_push_front(List *list, DataType elem);

ErrorType list_pop_front(List *list);

ErrorType list_insert_after(List *list, ListNode *node, DataType elem);

ErrorType list_erase_after(List *list, ListNode *node);

ErrorType list_push_back(List *list, DataType elem);

ErrorType list_pop_back(List *list);

ErrorType list_insert(List *list, unsigned index, DataType elem);

ErrorType list_erase(List *list, unsigned index);