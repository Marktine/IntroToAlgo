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
        LinkedList.travel(l);
        LinkedList.freeList(l);
    } else {
        printf("cannot init linked-list");
    }
   return 0;
}