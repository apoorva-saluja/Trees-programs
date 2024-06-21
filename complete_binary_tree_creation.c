#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insertLevelOrder(int arr[], struct node* root, int i, int n)
{
    if (i < n)
    {
        struct node* temp = createnode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2*i+1, n);
        root->right = insertLevelOrder(arr, root->right, 2*i+2, n);
    }
    return root;
}

void Inorder(struct node *root)
{
    if(root==NULL)return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

int height(struct node *root)
{
  if (root == NULL)
    return 0;
  else
  {
    int lheight = height(root-> left);
    int rheight = height(root -> right);
    if (lheight > rheight)
      return (lheight + 1);
    else return (rheight + 1);
  }
}

void CurrentLevel(struct node * root, int level)
{
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ",root -> data);
  else if (level > 1)
    {
    CurrentLevel(root -> left, level - 1);
    CurrentLevel(root -> right, level - 1);
  }
}


void LevelOrder(struct node * root)
{
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++)
    CurrentLevel(root, i);

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
    struct node* root = insertLevelOrder(arr, root, 0, n);
    Inorder(root);
    printf("\n");
    int h=height(root);
    printf("%d \n",h);
    LevelOrder(root);
    return 0;
}
