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

const struct ListNodeClass ListNode = {.newNode=&newNode};