#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data[2];
    struct node* left;
    struct node* right;
} NODE;

typedef struct {
    NODE* root;
} TREE;

NODE* makeNode(){
    NODE* pNew = (NODE*)malloc(sizeof(NODE));

    scanf("%d %d", &pNew->data[0], &pNew->data[1]);
    //scanf("%d %d", pNew->data, pNew->data + 1); // 이것도 가능
    pNew->left = NULL;
    pNew->right = NULL;
    return pNew;
} 

int compare(const void* a, const void* b) {
    int x1 = ((int*)a)[0];
    int y1 = ((int*)a)[1];
    int x2 = ((int*)b)[0];
    int y2 = ((int*)b)[1];

    if (x1 == x2) {
        return y1 - y2;
    } else {
        return x1 - x2;
    }
}

int insert(NODE **root, NODE *newPtr, int (*compare)(const void* a, const void* b)) {
    if (*root == NULL) {
        *root = newPtr;
        return 1;
    }

    if (compare(newPtr->data, (*root)->data) < 0) {
        return insert(&(*root)->left, newPtr, compare);
    } else {
        return insert(&(*root)->right, newPtr, compare);
    }
}

void inorder_traverse(NODE* root) {
    if (!root) return;
    inorder_traverse(root->left);
    printf("%d %d\n", root->data[0], root->data[1]);
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
        insert(&pTree->root, pNew, compare);
    }

    inorder_traverse(pTree->root);

    destroy(pTree->root);
    free(pTree);

}