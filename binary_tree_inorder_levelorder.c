#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTreeUtil(int inOrder[], int levelOrder[], int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    struct Node* node = newNode(levelOrder[0]);

    if (inStart == inEnd)
        return node;

    int inIndex = search(inOrder, inStart, inEnd, node->data);

    int leftSubTreeSize = inIndex - inStart;
    int rightSubTreeSize = inEnd - inIndex;

    int* leftLevelOrder = (int*)malloc(leftSubTreeSize * sizeof(int));
    int* rightLevelOrder = (int*)malloc(rightSubTreeSize * sizeof(int));

    int i, j = 0, k = 0;
    for (i = 1; i <= leftSubTreeSize; i++)
        leftLevelOrder[j++] = levelOrder[i];

    for (i = leftSubTreeSize + 1; i <= leftSubTreeSize + rightSubTreeSize; i++)
        rightLevelOrder[k++] = levelOrder[i];

    node->left = buildTreeUtil(inOrder, leftLevelOrder, inStart, inIndex - 1);
    node->right = buildTreeUtil(inOrder, rightLevelOrder, inIndex + 1, inEnd);

    free(leftLevelOrder);
    free(rightLevelOrder);

    return node;
}

struct Node* buildTree(int inOrder[], int levelOrder[], int size) {
    return buildTreeUtil(inOrder, levelOrder, 0, size - 1);
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    int inOrder[] = { 4, 8, 10, 12, 14, 20, 22 };
    int levelOrder[] = { 20, 8, 22, 4, 12, 10, 14 };

    int n = sizeof(inOrder) / sizeof(inOrder[0]);

    struct Node* root = buildTree(inOrder, levelOrder, n);

    printf("Inorder traversal of the constructed tree:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
