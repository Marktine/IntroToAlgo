#ifndef H_LIST_NODE
#define H_LIST_NODE

// ListNode instance struct definition
struct ListNode {
    // private:
    int value;
    struct ListNode* next;
    struct ListNode* prev;
};

// ListNodeClass struct definition
extern const struct ListNodeClass {
    // public:
    struct ListNode* (*newNode) (int data);
    void (*freeNode)(struct ListNode* this);
} ListNode;

#endif