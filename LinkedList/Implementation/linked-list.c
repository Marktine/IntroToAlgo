/*
 * TODOS:
 *      - Implement unshift
 *      - Implement shift
 * */

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
    // Increase length by 1 when item is successfully added
    this->length++;
    return 1;
}

// travel through the linked-list and print out node's value
static void travel(struct LinkedList* this)
{
    if (this != NULL)
    {
        if (this->phead != NULL)
        {
            if (this->phead == this->ptail)
            {
                printf("%d", this->phead->value);
            } 
            else
            {
                struct ListNode* t = this->phead;
                while(t != NULL)
                {
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
    this->length = 0;
    while(this->phead != NULL) {
        tmp = this->phead;
        this->phead = this->phead->next;
        ListNode.freeNode(tmp);
    }
    return 1;
}

static int insertBefore(struct LinkedList* this, struct ListNode* node, int data)
{
    if (this != NULL && this->phead != NULL && node != NULL) {
        struct ListNode* newNode = ListNode.newNode(data);
        node->prev->next = newNode;
        newNode->prev = node->prev;
        newNode->next = node;
        node->prev = newNode;
        this->length++;
        return this->length;
    }
    return 0;
}

static int insertAfter(struct LinkedList* this, struct ListNode* node, int data)
{
    if (this != NULL && this->phead != NULL && node != NULL) {
        struct ListNode* newNode = ListNode.newNode(data);
        newNode->prev = node;
        newNode->next = node->next;
        node->next->prev = newNode;
        node->next = newNode;
        this->length++;
        return this->length;
    } 
    return 0;
}

static struct ListNode* pop(struct LinkedList* this) {
    if (this != NULL && this->ptail != NULL) {
        struct ListNode* old_tail = this->ptail;
        struct ListNode* prev_tail = this->ptail->prev;
        prev_tail->next = NULL;
        this->ptail = prev_tail;
        this->length--;
        return old_tail;
    }
    else
    {
        return NULL;
    }
}

static int unshift(struct LinkedList* this, int data) {

}

static int shift(struct LinkedList* this, int data) {

}

static int getLength(struct LinkedList* this) {
    return this->length;
}

static struct ListNode* getNode(struct LinkedList* this, int index) {
    if (index >= 0 && index < this->length) {
        struct ListNode* temp = this->phead;
        int i = 0;
        while(temp != NULL) {
            if (i == index) {
                return temp;
            }
            i++;
            temp = temp->next;
        }
    }
    return NULL;
}

const struct LinkedListClass LinkedList =
{
    .pop=&pop,
    .push=&push,
    //.shift=&shift,
    .travel=&travel,
    .getNode=&getNode,
    .newList=&newList,
    //.unshift=&unshift,
    .freeList=&freeList,
    .getLength=&getLength,
    .insertAfter=&insertAfter,
    .insertBefore=&insertBefore,
};
