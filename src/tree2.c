/*
    DIMITRIS GAVOURAS
    03145
*/
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct pre_order {
    int value;
    struct pre_order *nxt;
};

typedef struct path_root {
    int value;
    struct path_root *nxt;
}path_t;

void insertNew_nodes (struct pre_order **preOrder, int number){
    struct pre_order *search, *curr = NULL;

    curr = (struct pre_order *) malloc (sizeof(struct pre_order));

    if (curr == NULL){
        *preOrder = NULL;
        perror ("ERROR");
        exit (-42);
    }
    curr->value = number;
    curr->nxt = NULL;

    search = *preOrder;
    if (search == NULL){
        
        *preOrder = curr;
    }
    else{

        for (; search->nxt != NULL; search = search->nxt){
            if (search->value == number){
                printf ("OXI TO IDIO");
                exit(-42);
            }
        }
        search->nxt = curr;
    }
}

int find_value1 (tree_t *tree, path_t **path_value1, int value1){
    node_t *node = tree->root;
    path_t *curr = *path_value1, *new_node = NULL;
    int found = 0;

    if (node == NULL){
        return 0;
    }

    while (1){
        if (node->value == value1){
            found = 1;
            break;
        }
        else if (node->value > value1){
            if (node->left == NULL){
                break;
            }
            node = node->left;
        }
        else {
            if (node->right == NULL){
                break;
            }
            node = node->right;
        }
    }

    while (found > 0){
        if (found == 1) {
            (*path_value1)->value = value1;
            found++;
            node = node->parent;
            if (node == NULL){
                break;
            }
            continue;
        }
        new_node = (path_t*)malloc(sizeof(path_t));
        if (new_node == NULL){
            perror("ERROR");
            exit(-42);
        }
        new_node->value = 0;
        new_node->nxt = NULL;

        new_node->value = node->value;
        curr->nxt = new_node;
        curr = curr->nxt;
        node = node->parent;

        if (node == NULL){
            break;
        }
        found++;
    }

    if (found == 0){
        //NOT FOUND
        return 0;
    }

    return 1;
}

int find_value2 (tree_t *tree, path_t **path_value2, int value2){
    node_t *node = tree->root;
    path_t *curr = *path_value2, *new_node = NULL;
    int found = 0;

    if (node == NULL){
        return 0;
    }
    //path_value2 = NULL;

    while (1){
        new_node = (path_t*)malloc(sizeof(path_t));
        if (new_node == NULL){
            perror("ERROR");
            exit(-42);
        }
        new_node->value = 0;
        new_node->nxt = NULL;

        if (node->value == value2){
            if (found == 0) {
                (*path_value2)->value = value2;
                found++;
                free (new_node);
                break;
            }
            new_node->value = value2;
            curr->nxt = new_node;
            break;
        }
        else if (node->value > value2){
            if (node->left == NULL){
                break;
            }
            if (found == 0) {
                (*path_value2)->value = node->value;
                found++;
                node = node->left;
                free (new_node);
                continue;
            }
            new_node->value = node->value;
            curr->nxt = new_node;
            node = node->left;
        }
        else {
            //node->value < value1
            if (node->right == NULL){
                break;
            }
            if (found == 0) {
                (*path_value2)->value = node->value;
                found++;
                node = node->right;
                free (new_node);
                continue;
            }
            new_node->value = node->value;
            curr->nxt = new_node;
            node = node->right;
        }
        curr = curr->nxt;
    }

    if (found == 0){
        free(new_node);
        //NOT FOUND
        return 0;
    }

    return 1;
}



void search_overlap (path_t *pathRoot1, path_t *pathRoot2, path_t *pathRoot_h){
    path_t *curr1, *curr2, *currT, *curr_free, *curr_h;

    for (currT = pathRoot_h, curr2 = pathRoot2 ;currT!=NULL && curr2!= NULL; currT = currT->nxt, curr2 = curr2->nxt){    

        if (currT->nxt==NULL || curr2->nxt== NULL){
            break;
        }
        if (currT->nxt->value != curr2->nxt->value){
            break;
        }
    }

    for (curr1 = pathRoot1;curr1 != NULL; curr1= curr1->nxt){
        if (curr1->value == currT->value){
            break;
        }
    }

    for (curr_free = curr1->nxt; curr_free != NULL;){
        curr_h = curr_free;
        curr_free = curr_free->nxt;
        free(curr_h);
    }    
    curr1->nxt = curr2->nxt;
    for (curr_free = pathRoot2; curr_free != curr2;){
        curr_h = curr_free;
        curr_free = curr_free->nxt;
        free(curr_h);
    }

    free (curr2);

}

void printPath (path_t *preOrder){
    path_t *curr;

    for (curr = preOrder; ; curr = curr->nxt){
        if (curr == NULL){
            continue;
        }
        printf (" %d", curr->value);

        if (curr->nxt == NULL){
            break;
        }
    }
    printf ("\n");
}

void free_path (path_t *pathRoot){
    path_t *curr, *tmp;
    curr = pathRoot;

    while (curr != NULL){
        tmp = curr;
        curr = curr->nxt;
        free (tmp);
    }
}

int main (int argc, char *argv[]){
    int number=0, value1=0, value2=0, not_found=0;
    struct pre_order *preOrder, *curr;
    tree_t *tree;
    path_t *pathRoot1, *pathRoot2, *pathRoot_h;

    preOrder = NULL;

    /*put everything in a list*/
    while(1){

        scanf (" %d", &number);

        if (number <= 0 ){
            break;
        }

        insertNew_nodes (&preOrder, number);
    }

    tree = create_tree();
    number = 0;

    /*start puting in tree the list one by one
    then free theat node and move on*/
    while (1){
        number = preOrder->value;

        btree_insert(tree, number);

        preOrder->value= 0;
        if (preOrder->nxt == NULL){
            free(preOrder);
            break;
        }

        curr = preOrder;
        preOrder = preOrder->nxt;
        free(curr);

    }

    printf ("Enter 2 integers: ");
    scanf ("%d %d", &value1, &value2);

    pathRoot1 = (path_t*) malloc (sizeof (path_t));
    if (pathRoot1 == NULL) {
        return (-1);
    }
    pathRoot1->value = 0;

    pathRoot2 = (path_t*) malloc (sizeof (path_t));
    if (pathRoot2 == NULL) {
        return (-1);
    }
    pathRoot2->value = 0;

    pathRoot_h = (path_t*) malloc (sizeof (path_t));
    if (pathRoot_h == NULL) {
        return (-1);
    }
    pathRoot_h->value = 0;

    not_found = find_value1 (tree, &pathRoot1, value1);
    if (not_found == 0){
        //not found
        printf ("%d not found!\n", value1);
    }

    not_found = find_value2 (tree, &pathRoot_h, value1);
    if (not_found == 0){
        //not found
        printf ("%d not found!\n", value1);
    }

    not_found = find_value2 (tree, &pathRoot2, value2);
    if (not_found == 0){
        //not found
        printf ("%d not found!\n", value2);
    }
    
    search_overlap (pathRoot1, pathRoot2, pathRoot_h);
    printf ("\nPath is:");
    printPath (pathRoot1);

    free_path (pathRoot1);
    free_path (pathRoot_h);

    free_tree (tree->root);
    free (tree);
    return 0;
}