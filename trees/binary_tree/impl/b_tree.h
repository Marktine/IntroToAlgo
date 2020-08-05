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
    struct b_tree (*newTree)();
} b_tree;

#endif