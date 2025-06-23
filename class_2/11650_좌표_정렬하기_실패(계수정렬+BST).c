#include <stdio.h>
#include <stdlib.h>

#define OFFSET 100000

typedef struct node {
    int y;
    struct node *left;
    struct node *right;
} NODE;

typedef struct {
    NODE *root;
} TREE;

NODE *makeNode (int y) {
    NODE *pNew = (NODE*)malloc(sizeof(NODE));
    pNew->y = y;
    pNew->left = NULL;
    pNew->right = NULL;
    return pNew;
}

TREE *createTree(int y) {
    TREE *pTree = (TREE*)malloc(sizeof(TREE));
    NODE *root = makeNode(y);
    pTree->root = root;
    return pTree;
}

void insertNode (NODE **root, NODE *pNew) {
    if (*root == NULL) {
        *root = pNew;
        return;
    }
    if (pNew->y < (*root)->y) {
        insertNode(&(*root)->left, pNew);
    } else {
        insertNode(&(*root)->right, pNew);
    }
}

void inorderTraverse (int x, NODE *root) {
    if (!root) return;
    inorderTraverse(x, root->left);
    printf("%d %d\n", x, root->y);
    inorderTraverse(x, root->right);
}

void destroyTree (NODE *root) {
    if (!root) return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
    return;
}

int main() {

    int N = 0;
    scanf("%d", &N);

    TREE **plots = (TREE**)calloc(2*OFFSET+1, sizeof(TREE*));

    int x, y;
    TREE *pTree;
    NODE *pNew;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        if (!plots[x+OFFSET]) {
            plots[x+OFFSET] = createTree(y);
            continue;
        }
        pTree = plots[x+OFFSET];
        pNew = makeNode(y);
        insertNode(&pTree->root, pNew);
    }

    for (int i = 0; i <= 2*OFFSET; i++) {
        if (plots[i]) {
            inorderTraverse(i-OFFSET, plots[i]->root);
        }
    }

    for (int i = 0; i <= 2*OFFSET; i++) {
        if (plots[i]) {
            destroyTree(plots[i]->root);
            free(plots[i]);
        }
    }
    free(plots);
}
