#include "stdio.h"
#include "stdlib.h"
#include "../linked-list.h"

int main() {
    struct LinkedList* l = LinkedList.newList();
    struct ListNode* shifted_el;
    struct ListNode* popped_out_node;
    struct ListNode* n;
    struct ListNode* n1;
    if (l != NULL)
    {
        printf("Success init list\n");
        // push 1st item
        LinkedList.push(l, 10);
        // push 2nd item `phead == ptail` case
        LinkedList.push(l, 20);
        // push 3rd item and more
        LinkedList.push(l, 40);
        n = LinkedList.getNode(l, 2);
        n1 = LinkedList.getNode(l, 1);
        if (n != NULL) {
            LinkedList.insertBefore(l, n, 100);
            LinkedList.travel(l);
        } else {
            printf("Failed to get node\n");
        }
        popped_out_node = LinkedList.pop(l);
        if (popped_out_node != NULL)
        {
            printf("popped out node value: %d\n", popped_out_node->value);
            printf("\nList after pop out a node\n");
            LinkedList.travel(l);
        } else {
            printf("Cannot pop the node out of the linked-list\n");
        }
        if (n1 != NULL)
        {
            LinkedList.insertAfter(l, n1, 200);
            printf("\nLinked-list after insert n1\n");
            LinkedList.travel(l);
        } else
        {
            printf("Failed to get n1\n");
        }
        printf("\n-----------------\n");
        LinkedList.unshift(l, 10);
        LinkedList.travel(l);
        shifted_el = LinkedList.shift(l);
        if (shifted_el != NULL) {
            printf("\n--------------------\n");
            printf("Shifted out element value: %d\n", shifted_el->value);
            LinkedList.travel(l);
        } else
        {
            printf("Failed to shift element out of linked-list\n");
        }
        LinkedList.freeList(l);
        ListNode.freeNode(popped_out_node);
        ListNode.freeNode(shifted_el);
    } else
    {
        printf("cannot init linked-list");
    }
   return 0;
}