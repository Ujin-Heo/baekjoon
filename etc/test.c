#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} NODE;

typedef struct {
    NODE* root;
} TREE;

NODE* makeNode(){
    NODE* pNew = (NODE*)malloc(sizeof(NODE));

    scanf("%d", &pNew->data);
    pNew->left = NULL;
    pNew->right = NULL;
    return pNew;
} 

int insert(NODE **root, NODE *newPtr) {
    if (*root == NULL) {
        *root = newPtr;
        return 1;
    }

    if (newPtr->data < (*root)->data) {
        return insert(&(*root)->left, newPtr);
    } else {
        return insert(&(*root)->right, newPtr);
    }
}

int main() {
    NODE** ptr = NULL;
    NODE** pptr = NULL;

    TREE* pTree = (TREE*)malloc(sizeof(TREE));
    pTree->root = NULL;
    NODE* root_node = makeNode();
    root_node->data = 3;
    insert(&pTree->root, root_node);

    ptr = &pTree->root->left;
    NODE* branch_node = makeNode();
    branch_node->data = 1;
    insert(&pTree->root, branch_node);
    pptr = &branch_node;
    printf("%p", ptr);
    printf("%p", pptr);
}