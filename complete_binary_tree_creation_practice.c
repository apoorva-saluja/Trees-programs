//creation of a complete binary tree with all 4 traversals practice

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

void inorder(struct node *root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int height(struct node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
            return (lheight+1);
        else
            return(rheight+1);
    }
}

void currentlevel(struct node *root,int level)
{
    if(root==NULL)
        return;
    else if(level==1)
    {
        printf("%d ",root->data);
    }
    else
    {
        currentlevel(root->left,level-1);
        currentlevel(root->right,level-1);
    }
}

void levelorder(struct node *root)
{
    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
    {
        currentlevel(root,i);
    }
}

struct node *insertlevelorder(int arr[],struct node *root,int i, int n)
{
    if(i<n)
    {
        struct node *temp=createnode(arr[i]);
        root=temp;
        root->left=insertlevelorder(arr,root->left,2*i+1,n);
        root->right=insertlevelorder(arr,root->right,2*i+2,n);
    }
    return root;
}

int main()
{
    int n;
    scanf("%d ",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct node *root=insertlevelorder(arr,root,0,n);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    levelorder(root);
    printf("\n");
}
