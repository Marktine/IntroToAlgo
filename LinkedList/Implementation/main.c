#include "stdio.h"
#include "stdlib.h"

// linked-list node struct definition
struct node {
    int data;
    NODE* next;
};
typedef struct node NODE;

// linked-list definition
struct list {
    NODE* phead;
    NODE* ptail;
};
typedef struct list LIST;

// Init new a node
NODE* newNode(int data) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
};

// Linked-list initialize
void init(LIST* l) {
    l->phead = NULL;
    l->ptail = NULL;
};

// push a node into a linked-list
// return 0 if node is successfully pushed into linked-list
// return -1 if list is not initialized
int push(LIST* l,NODE* node) {
    if (l != NULL) {
        if (l->phead == NULL) {
            l->phead = node;
            l->ptail = node;
        } else {
            //  If linked-list only contains one member
            // then we have to point `l->phead->next` to the new node
            if (l->phead == l->ptail) {
                l->phead->next = node;
            }
            NODE* temp = l->ptail;
            temp->next = node;
            l->ptail = node;
            free(temp);
        }
        return 0;
    }
    return -1;
}

int main() {
    
    return 0;    
}