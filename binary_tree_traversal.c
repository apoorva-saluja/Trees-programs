#include <stdio.h>
#include <stdlib.h>

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
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void Inorder(struct node *root)
{
    if(root==NULL)return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void Preorder(struct node *root)
{
    if(root==NULL)return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct node *root)
{
    if(root==NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

struct node *insert_left(struct node *root,int val)
{
    root->left=createnode(val);
    return root->left;
}

struct node *insert_right(struct node *root,int val)
{
    root->right=createnode(val);
    return root->right;
}

int main()
{
    struct node *root=createnode(1);
    insert_left(root,2);
    insert_right(root,3);
    Inorder(root);
    printf("\n");
    Preorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
}
