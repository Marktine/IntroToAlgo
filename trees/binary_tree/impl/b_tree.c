#include "b_tree.h"

static struct b_tree newTree() {
    return (struct b_tree) {
        .height=0,
        .levels=0,
        .root=NULL,
    };
};

const struct b_tree_class b_tree={
    .newTree=&newTree
};