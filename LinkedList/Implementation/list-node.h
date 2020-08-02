#ifndef H_LIST_NODE
#define H_LIST_NODE

// ListNode instance struct definition
struct ListNode {
    int value;
    struct ListNode* next;
    struct ListNode* prev;
};

// ListNodeClass struct definition
extern const struct ListNodeClass {
    struct ListNode* (*newNode) (int data);
} ListNode;

#endif