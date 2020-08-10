#include "stdio.h"
#include "stdlib.h"
#include "../linked-list.h"

int main() {
    struct LinkedList* l = LinkedList.newList();
    if (l != NULL) {
        printf("Success init list\n");
        // push 1st item
        LinkedList.push(l, 10);
        // push 2nd item `phead == ptail` case
        LinkedList.push(l, 20);
        // push 3rd item and more
        LinkedList.push(l, 40);
        struct ListNode* n = LinkedList.getNode(l, 1);
        if (n != NULL) {
            LinkedList.insertBefore(l, n, 100);
            LinkedList.travel(l);
        } else {
            printf("Failed to get node\n");
        }
        struct ListNode* popped_out_node = LinkedList.pop(l);
        if (popped_out_node != NULL) {
            printf("popped out node value: %d\n", popped_out_node->value);
            printf("\nList after pop out a node\n");
            LinkedList.travel(l);
        } else {
            printf("Cannot pop the node out of the linked-list\n");
        }
        LinkedList.freeList(l);
    } else {
        printf("cannot init linked-list");
    }
   return 0;
}