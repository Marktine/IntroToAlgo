#ifndef H_LINKED_LIST
#define H_LINKED_LIST
#include "list-node.h"

struct LinkedList
{
    /* data */
    int length;
    struct ListNode* phead;
    struct ListNode* ptail;
};

extern const struct LinkedListClass
{
    // init new linked-list
    struct LinkedList* (*newList)();
    // travel through each node in linked-list and print out the value
    void(*travel)(struct LinkedList* this);
    // get node by index
    struct ListNode* (*getNode)(struct LinkedList* this, int index);
    // get linked-list length
    int (*getLength)(struct LinkedList* this);
    // deallocate all nodes in linked-list and the list itself
    int (*freeList)(struct LinkedList* this);
    // push an item into linked-list
    int (*push)(struct LinkedList* this, int data);
    // pop an item out of linked-list
    struct ListNode* (*pop)(struct LinkedList* this);
    // Add a node at the start of the linked-list
    int (*unshift)(struct LinkedList* this, int data);
    // insert a node before a node in linked-list
    int (*insertBefore)(struct LinkedList* this, struct ListNode* node, int data);
    // insert a node after a node in linked-list
    int (*insertAfter)(struct LinkedList* this, struct ListNode* node, int data);
    // remove a node at the start of the linked-list then returns that node
    struct ListNode* (*shift)(struct LinkedList* this);
} LinkedList;
#endif
