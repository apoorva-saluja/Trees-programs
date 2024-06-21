#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertElement(struct Node *root,int data)
{
    if(root==NULL)
       {
           root=createNode(data);
           return;
       }
    struct Node *temp;
    struct Node **queue=(struct Node**)malloc(100*sizeof(struct Node*));
    int front=-1;
    int rear=-1;
    queue[++rear]=root;
    while(front!=rear)
    {
        temp=queue[++front];
        if(temp->left==NULL)
        {
            temp->left=createNode(data);
            free(queue);
            return;
        }
        else
        {
            queue[++rear]=temp->left;
        }
        if(temp->right==NULL)
        {
            temp->right=createNode(data);
            free(queue);
            return;
        }
        else
        {
            queue[++rear]=temp->right;
        }
    }
    free(queue);
}
/*
void insertElement(struct Node* root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return;
    }
    struct Node* temp;
    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = -1;
    int rear = -1;

    queue[++rear] = root;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->left == NULL)
        {
            temp->left = createNode(data);
            free(queue);
            return;
        }
        else
        {
            queue[++rear] = temp->left;
        }
        if (temp->right == NULL)
        {
            temp->right = createNode(data);
            free(queue);
            return;
        }
        else
        {
            queue[++rear] = temp->right;
        }
    }

    free(queue);
}
*/
void preorder(struct Node *node)
{
    if(node==NULL)return;
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

// Function to print the binary tree using level order traversal
int height(struct Node *root)
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

void currentlevel(struct Node *root,int level)
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

void levelorder(struct Node *root)
{
    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
    {
        currentlevel(root,i);
    }
}

int main()
{
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);
    preorder(root);
    printf("\n");
    printf("Binary tree before insertion: ");
    levelorder(root);
    printf("\n");
    int element = 6;
    insertElement(root, element);
    preorder(root);
    printf("\n");
    printf("\nBinary tree after insertion of %d: ", element);
    levelorder(root);

    return 0;
}
