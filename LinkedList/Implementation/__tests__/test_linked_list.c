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
        struct ListNode* n = LinkedList.getNode(l, 2);
        if (n != NULL) {
            LinkedList.insertBefore(l, n, 100);
            LinkedList.travel(l);
            LinkedList.freeList(l);
        } else {
            printf("Failed to get node\n");
        }
    } else {
        printf("cannot init linked-list");
    }
   return 0;
}