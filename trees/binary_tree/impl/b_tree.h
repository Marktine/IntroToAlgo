#ifndef H_B_TREE
#define H_B_TREE

#include "bt_node.c"

struct b_tree {
    // private:
    int levels;
    int height;
    struct bt_node* root;
    // protected:
};

extern const struct b_tree_class {
    // public:
    struct b_tree (*newTree)();
    int (*getLevel)(struct b_tree* this);
    int (*getHeight)(struct b_tree* this);
} b_tree;

#endif