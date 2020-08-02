#include "stddef.h"
#include "list-node.h"

static struct ListNode newNode(int data)
{
    return (struct ListNode) {
        .value = data,
        .next=NULL,
    };
}

const struct ListNodeClass ListNode = {.newNode=&newNode};