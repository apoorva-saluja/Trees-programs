#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
};

int height(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
        {
            return (lheight+1);
        }
        else
        {
            return (rheight+1);
        }
    }
}

void printcurrentlevel(struct node *node,int level)
{
    if(node==NULL)
    {
        return;
    }
    else if(level==1)
    {
        printf("%d ",node->data);
    }
    else if(level>1)
    {
        printcurrentlevel(node->left,level-1);
        printcurrentlevel(node->right,level-1);
    }
}

void printlevelorder(struct node *root)
{
    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
    {
        printcurrentlevel(root,i);
    }
}

int main()
{
    struct node *root=createnode(1);
    root->left=createnode(10);
    root->right=createnode(3);
    root->left->left=createnode(40);
    root->left->right=createnode(5);
    root->right->left=createnode(6);
    root->right->right=createnode(7);
    printlevelorder(root);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int height(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
            return (lheight+1);
        else
            return (rheight+1);
    }
}

void printcurrentlevel(struct node *node,int level)
{
    if(node==NULL)
    {
        return;
    }
    else if(level==1)
    {
        printf("%d ",node->data);
    }
    else if(level>1)
    {
        printcurrentlevel(node->left,level-1);
        printcurrentlevel(node->right,level-1);
    }
}

void printlevelorder(struct node *root)
{
    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
    {
        printcurrentlevel(root,i);
    }
}

int main()
{
    struct node *root=createnode(1);
    root->left=createnode(10);
    root->right=createnode(3);
    root->left->left=createnode(40);
    root->left->right=createnode(5);
    root->right->left=createnode(6);
    root->right->right=createnode(7);
    printlevelorder(root);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int height(struct node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        int lheight=height(node->left);
        int rheight=height(node->right);
        if(lheight>rheight)
            return (lheight+1);
        else
            return (rheight+1);
    }
}

void printcurrentlevel(struct node *root,int level)
{
    if(root==NULL)
    {
        return ;
    }
    else if(level==1)
    {
        printf("%d ",root->data);
    }
    else if(level>1)
    {
        printcurrentlevel(root->left,level-1);
        printcurrentlevel(root->right,level-1);
    }
}

void printlevelorder(struct node *root)
{
    int h=height(root);
    int i;
    for(int i=1;i<=h;i++)
    {
        printcurrentlevel(root,i);
    }
}

int main()
{
    struct node *root=createnode(1);
    root->left=createnode(10);
    root->right=createnode(3);
    root->left->left=createnode(40);
    root->left->right=createnode(5);
    root->right->left=createnode(6);
    root->right->right=createnode(7);
    printlevelorder(root);
    return 0;
}
*/
