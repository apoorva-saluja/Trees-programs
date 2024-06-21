/*
Insert a value in a Binary Search Tree
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void inorder(struct node *root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


// A utility function to insert
// a new node with given data in BST
struct node* insert(struct node* root, int data)
{
	if (root == NULL)
		return createnode(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);

	return root;
}

int main()
{
    int n;
    int key;
    scanf("%d",&n);
    struct node *root=NULL;
    int x;
    scanf("%d",&x);
    root=createnode(x);
    for(int i=1;i<n;i++)
    {
        insert(root,key);
    }
    inorder(root);
    return 0;
}



/*
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

struct node* insert(struct node *root, int x)
{
  if (root == NULL)
  return createnode(x);

  else if (x > root -> data)
    root -> right = insert(root -> right, x);
  else
    root -> left = insert(root -> left, x);
  return root;
}

void inorder(struct node *root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    int n;
    int key;
    scanf("%d",&n);
    struct node *root;
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&key);
        insert(root,key);
    }
    inorder(root);
    return 0;
}
*/
