#include "stddef.h"
#include "stdlib.h"
#include "list-node.h"

static struct ListNode* newNode(int data)
{
    struct ListNode* n =
        (struct ListNode*) malloc(sizeof(struct ListNode));
    n->value = data;
    n->next = NULL;
    return n;
}

static void freeNode(struct ListNode* this) {
    if (this != NULL) {
        this->value = 0;
        free(this);
    }
}

const struct ListNodeClass ListNode = {
    .newNode=&newNode,
    .freeNode=&freeNode,
};