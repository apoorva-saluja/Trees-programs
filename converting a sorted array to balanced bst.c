#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node* createnode(int val)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->value = val;
    node->left = NULL;
    node->right  =  NULL;
    return node;
}

struct node *bst(int arr[], int first, int last)
{
    int mid;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (first > last)
        return NULL;
    mid = (first + last) / 2;
    temp = createnode(arr[mid]);
    temp->left = bst(arr, first, mid - 1);
    temp->right = bst(arr, mid + 1, last);
    return temp;
}

void preorder(struct node *root)
{
    if(root==NULL)return;
    printf("%d->", root->value);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 60, 80, 90};
    struct node *root = (struct node*)malloc(sizeof(struct node));
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given sorted array is\n");
    for (int i = 0;i < n;i++)
        printf("%d\t", arr[i]);
    root = bst(arr, 0, n - 1);
    printf("\n The preorder traversal of binary search tree is as follows\n");
    preorder(root);
    printf("\n");
    return 0;
}
