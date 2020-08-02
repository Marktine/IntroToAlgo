#ifndef H_LIST_NODE
#define H_LIST_NODE

struct ListNode {
    int value;
    struct ListNode* next;
};

extern const struct ListNodeClass {
    struct ListNode (*newNode) (int data);
} ListNode;

#endif