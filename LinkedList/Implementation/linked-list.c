#include "stdio.h"
#include "stdlib.h"
#include "linked-list.h"

static struct LinkedList* newList()
{
    struct LinkedList* newList =
        (struct LinkedList*) malloc(sizeof(LinkedList));
    newList->phead = NULL;
    newList->ptail = NULL;
    return newList;
}

static int push(struct LinkedList* this,int data)
{
    struct ListNode* newNode = ListNode.newNode(data);
    if (this->phead == NULL) {
        this->phead = newNode;
        this->ptail = newNode;
    } else {
        if (this->phead == this->ptail) {
            this->phead->next = newNode;
            this->ptail = newNode;
            this->ptail->prev = this->phead;
        } else {
            this->ptail->next = newNode;
            newNode->prev = this->ptail;
            this->ptail = newNode;
        }
    }
    return 1;
}

static void travel(struct LinkedList* this)
{
    if (this != NULL) {
        if (this->phead != NULL) {
        if (this->phead == this->ptail) {
            printf("%d", this->phead->value);
        } else {
            struct ListNode* t = this->phead;
                while(t != NULL) {
                    printf("%d\n", t->value);
                    t = t->next;
                }
            }
        }
    }
}

static int freeList(struct LinkedList* this)
{
    if (this == NULL) return 0;
    struct ListNode* tmp;
    while(this->phead != NULL) {
        tmp = this->phead;
        this->phead = this->phead->next;
        free(tmp);
    }
}

const struct LinkedListClass LinkedList =
{
    .newList=&newList,
    .push=&push,
    .travel=&travel,
    .freeList=&freeList,
};