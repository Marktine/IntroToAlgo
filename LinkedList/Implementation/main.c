#include "stdio.h"
#include "stdlib.h"

// node structure definition
struct node {
    int data;
    struct node* next;
};
typedef struct node NODE;

// linked-list structure definition
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
// Return 0 if linked-list is successfully initialized
// Return -1 if linked-list is already initialized
int init(LIST* l) {
    // If linked-list is NULL then allocate memory for linked-list
    if (l == NULL) {
        l = (LIST*) malloc(sizeof(LIST));
    }
    if (l->phead != NULL) {
        return -1;
    }
    l->phead = NULL;
    l->ptail = NULL;
    return 0;
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

void travel(LIST* l) {
    if (l != NULL) {
        if (l->phead == l->ptail) {
            printf("%d", l->phead->data);
        } else {
            NODE* n = l->phead;
            while(n != NULL) {
                printf("%d", n->data);
                n = n->next;
            }
        }
    }
}

int main() {
    LIST* l;
    NODE* n1 = newNode(20);
    NODE* n2 = newNode(30);
    NODE* n3 = newNode(40);
    int initResult = init(l);
    if (initResult == 0) {
        push(l, n1);
        push(l, n2);
        push(l, n3);
        travel(l);
    } else {
        printf("Linked-list is already initialized\n");
        return 1;
    }
    free(l);
    free(n1);
    free(n2);
    free(n3);
    return 0;
}