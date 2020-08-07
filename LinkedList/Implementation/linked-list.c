/*
 * TODOS:
 *      - Implement insert method
 *      - Implement pop method
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

static int insertBefore(struct LinkedList* this, int index, int data) {
    int i = 0;
    struct ListNode* newNode = ListNode.newNode(data);
    struct ListNode* tmp = this->phead;
    while(i != index && tmp->next != NULL) {
        if (i == index) {
            struct ListNode* prev_node = tmp->prev;
            tmp->prev = newNode;
            newNode->next = tmp;
            newNode->prev = prev_node;
        } else {
            tmp = tmp->next;
            i++;
        }
    }
}

static int insertAfter(struct LinkedList* this, int index, int data) {
    
}

static struct ListNode pop(struct LinkedList* this) {

}

static int unshift(struct LinkedList* this, int data) {

}

static int shift(struct LinkedList* this, int data) {

}

const struct LinkedListClass LinkedList =
{
    .pop=&pop,
    .push=&push,
    .shift=&shift,
    .travel=&travel,
    .newList=&newList,
    .unshift=&unshift,
    .freeList=&freeList,
    .insertAfter=&insertAfter,
    .insertBefore=&insertBefore,
};
