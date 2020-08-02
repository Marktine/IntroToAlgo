#ifndef H_LINKED_LIST
#define H_LINKED_LIST
#include "list-node.h"

struct LinkedList
{
    /* data */
    struct ListNode* phead;
    struct ListNode* ptail;
};

extern const struct LinkedListClass
{
    // init new linked-list
    struct LinkedList (*newList)();
    int (*push)(struct LinkedList* this, int data);
    void(*travel)(struct LinkedList* this);
    int (*freeList)(struct LinkedList* this);
} LinkedList;
#endif