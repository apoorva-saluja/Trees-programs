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

int main()
{
    struct node *root=createnode(1);
    root->left=createnode(2);
    int h=height(root);
    printf("%d ",h);
}
