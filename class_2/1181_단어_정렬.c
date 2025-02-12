#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *data;
    struct node *left;
    struct node *right;
} NODE;

typedef struct {
    NODE *root;
} TREE;

TREE *createTree() {
    TREE *pTree = (TREE *)malloc(sizeof(TREE));
    pTree->root = NULL;

    return pTree;
}

NODE *createNode(char *buffer) {
    NODE *pNew = (NODE *)malloc(sizeof(NODE));
    pNew->data = strdup(buffer);
    pNew->left = NULL;
    pNew->right = NULL;

    return pNew;
}

int compare(const char *a, const char *b) {
    int diff = strlen(a) - strlen(b);
    if (diff != 0) {
        return diff;
    } else {
        return strcmp(a, b);
    }
}

static void _insert(NODE **root, NODE *pNew) {
    if (*root == NULL) {
        *root = pNew;
        return;
    }

    int cmp = compare((*root)->data, pNew->data);
    if (cmp < 0) {
        _insert(&((*root)->right), pNew);
    } else if (cmp > 0) {
        _insert(&((*root)->left), pNew);
    } else {
        free(pNew->data);
        free(pNew);
        return;
    }
}

void insertTree(TREE *pTree, char *buffer) {
    NODE *pNew = createNode(buffer);
    _insert(&(pTree->root), pNew);
}

void _traverse(NODE *root) {
    if (root == NULL) return;

    _traverse(root->left);
    printf("%s\n", root->data);
    _traverse(root->right);
}

static void traverseTree(TREE *pTree) {
    _traverse(pTree->root);
}

void destroy(NODE *root) {
    if (root == NULL) return;

    destroy(root->left);
    destroy(root->right);
    free(root->data);
    free(root);
}

int main() {

    int N = 0;
    scanf("%d", &N);

    TREE *pTree = createTree();

    char buffer[60] = {0,};
    for (int i = 0; i < N; i++) {
        scanf("%s", buffer);
        insertTree(pTree, buffer);
    }

    traverseTree(pTree);

    destroy(pTree->root);
    free(pTree);

    return 0;
}