#include "stdio.h"
#include "stdlib.h"
#include "linked-list.h"

static struct LinkedList newList()
{
    return (struct LinkedList) {
        .phead=NULL,
        .ptail=NULL,
    };
}

static int push(struct LinkedList* this,int data)
{
    struct ListNode newNode = ListNode.newNode(data);
    if (this->phead == this->ptail) {
        this->phead->next = &newNode;
        this->ptail = &newNode;
    } else {
        struct ListNode* temp = this->ptail;
        temp->next = &newNode;
        this->ptail = &newNode;
        free(temp);
    }
    return 0;
}

static void travel(struct LinkedList* this)
{
    if (this != NULL) {
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
    .push=&push
};