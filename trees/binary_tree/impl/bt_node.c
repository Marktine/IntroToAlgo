#include "stdio.h"
#include "stdlib.h"
#include "bt_node.h"

static struct bt_node newNode(int data) {
    return (struct bt_node) {
        .data=data,
        .left=NULL,
        .right=NULL,
    };
};

const struct bt_node_class bt_node = {
    .newNode=&newNode,
};