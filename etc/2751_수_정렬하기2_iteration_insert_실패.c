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

static NODE* _search(TREE* pTree, int key, int* dir) {

    if (!pTree->root) {
        return NULL;
    }

    NODE* cur = pTree->root;
    NODE* prev = NULL;

    while (cur != NULL) {
        prev = cur;
        if (key < cur->data) {
            cur = cur->left;
            *dir = LEFT;
        } else {
            cur = cur->right;
            *dir = RIGHT;
        }
    }

    return prev;
}

void insert(TREE* pTree, NODE* pNew) {

    int dir;

    NODE* pPre = _search(pTree, pNew->data, &dir);

    if (!pPre) {
        pTree->root = pNew;
        return;
    }

    if (dir == LEFT) {
        pPre->left = pNew;
    } else {
        pPre->right = pNew;
    }
}

void inorder_traverse(NODE* root) {
    if (!root) return;
    inorder_traverse(root->left);
    printf("%d\n", root->data);
    inorder_traverse(root->right);
}

void destroy(NODE* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    free(root);
}

int main() {

    int N = 0;
    scanf("%d", &N);

    TREE* pTree = (TREE*)malloc(sizeof(TREE));
    pTree->root = NULL;

    for (int i = 0; i < N; i++) {
        NODE* pNew = makeNode();
        insert(pTree, pNew);
    }

    inorder_traverse(pTree->root);

    destroy(pTree->root);
    free(pTree);

}