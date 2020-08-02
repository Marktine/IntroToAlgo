#include "stdio.h"
#include "stdlib.h"
#include "linked-list.h"

int main() {
    struct LinkedList l = LinkedList.newList();
    LinkedList.push(&l, 10);
    LinkedList.push(&l, 20);
    LinkedList.push(&l, 50);
    return 0;
}