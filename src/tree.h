#ifndef TREE_H
#define TREE_H

typedef struct tree_node {
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
    int value;
}node_t;

typedef struct tree {
    node_t *root;
    int nodes;
}tree_t;

tree_t* create_tree ();

node_t* findP_insert (tree_t *tree, int number);

int btree_insert (tree_t *tree, int number);

void free_tree (node_t *node);

#endif