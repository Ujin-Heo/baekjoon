#include <stdio.h>
#include <stdlib.h>

// 일반적인 BST -> 랜덤한 입력에 대해서는 N개 입력 시간 복잡도가 O(NlogN)이지만, 정렬된 입력에 대해서는 O(N^2)임. -> 시간 초과 발생
// AVL Tree, Heap Sort, Counting Sort(계수 정렬) 중 하나를 사용.
// 계수 정렬이 코드가 제일 간단함.

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
        insert(&pTree->root, pNew);
    }

    inorder_traverse(pTree->root);

    destroy(pTree->root);
    free(pTree);

}