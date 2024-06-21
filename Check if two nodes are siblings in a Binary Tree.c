/*
Check if two nodes are siblings in a Binary Tree
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}

bool isSibling(struct node *root, int x, int y)
{
    if (root==NULL)
        return 0;
    bool a = false, b = false, c = false;
    if(root->left != NULL && root->right != NULL)
        a = ( (root->left->data == x && root->right->data == y) ||
              (root->left->data == y && root->right->data == x) );
    if(root->left != NULL)
        b = isSibling(root->left, x, y);
    if(root->right != NULL)
        c = isSibling(root->right, x, y);
    return (a || b || c);
}
int main()
{
    struct node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->right = createnode(5);
    int z=isSibling(root,2,3);
    printf("%d ",z);
}
