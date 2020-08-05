#ifndef H_BT_NODE
#define H_BT_NODE

struct bt_node {
   int data;
   struct bt_node* left;
   struct bt_node* right;
};

extern const struct bt_node_class {
    struct bt_node (*newNode)(int data);
} bt_node;

#endif