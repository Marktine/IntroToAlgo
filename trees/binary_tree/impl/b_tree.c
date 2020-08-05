#include "b_tree.h"

static struct b_tree newTree() {
    return (struct b_tree) {
        .height=0,
        .levels=0,
        .root=NULL,
    };
};

static int getHeight(struct b_tree* this) {
   return this->height;
}

static int getLevel(struct b_tree* this) {
    return this->levels;
}

const struct b_tree_class b_tree= {
    .newTree=&newTree,
    .getHeight=&getHeight,
    .getLevel=&getLevel
};