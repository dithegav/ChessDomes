#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree_t* create_tree (){
    tree_t *tree ;

    tree = (tree_t *)malloc (sizeof(tree_t));
    if (tree == NULL){
        perror("ERROR");
        exit(-42);
    }

    tree->root = NULL;
    tree->nodes = 0;
    return tree;

}

node_t* findP_insert (tree_t *tree, int number){
    node_t *curr;

    curr = tree->root;
    node_t *parent = curr;
    while (1){

        if (curr == NULL){
            break;
        }
        parent = curr;
        if (number < curr->value){
            curr = curr->left;
        }
        else if (number > curr->value){
            curr = curr->right;
        }
        else {
            return curr;
        }
    }

    if (curr == NULL){
        return parent;
    }
    return curr;

}

int btree_insert (tree_t *tree, int number){
    node_t *new_node;
    node_t *Rfind;

    Rfind = findP_insert(tree, number);
    if ((Rfind != NULL) && (Rfind->value == number)){
        return 1;
        /*key already exists*/
    }

    /*create the node for the tree*/
    new_node = (node_t *)malloc (sizeof(node_t));
    if (new_node == NULL){
        perror("ERROR");
        exit(-42);
    }
    new_node->parent = Rfind;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = number;

    if (Rfind != NULL){
        if (number > Rfind->value){
        Rfind->right = new_node;
        }
        else {
            //number < Rfind->left
            Rfind->left = new_node;
        }

    }
    else {
        /*put in root cause tree is empty*/
        tree->root = new_node;
    }
    tree->nodes++;
    return 1;
}

void free_tree (node_t *node){

    if (node == NULL){
        return ;
    }

    free_tree (node->left);

    free_tree (node->right);

    free (node);
}