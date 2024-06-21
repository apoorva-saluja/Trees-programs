#include <stdio.h>
#include <stdlib.h>
int flag=0;
int in_array[50];

struct node
{
  int data;
  struct node *right;
  struct node *left;
};

struct node* new_node(int x)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp -> data = x;
  temp -> left = NULL;
  temp -> right = NULL;

  return temp;
}
struct node* find_minimum(struct node * root) {
  if (root == NULL)
    return NULL;
  else if (root -> left != NULL)
    return find_minimum(root -> left);
  return root;
}

struct node* insert(struct node * root, int x)
{
  if (root == NULL)
    return new_node(x);
  else if (x > root -> data)
    root -> right = insert(root -> right, x);
  else
    root -> left = insert(root -> left, x);
  return root;
}


struct node* delete(struct node * root, int x)
{
  if (root == NULL)
    return NULL;
  if (x > root -> data)
    root -> right = delete(root -> right, x);
  else if (x < root -> data)
    root -> left = delete(root -> left, x);
  else
  {
    if (root -> left == NULL && root -> right == NULL)
    {
      free(root);
      return NULL;
    }

    else if (root -> left == NULL || root -> right == NULL)
    {
      struct node *temp;
      if (root -> left == NULL)
        temp = root -> right;
      else
        temp = root -> left;
      free(root);
      return temp;
    }
    else
    {
      struct node *temp = find_minimum(root -> right);
      root -> data = temp -> data;
      root -> right = delete(root -> right, temp -> data);
    }
  }
  return root;
}
int i=0;
void InTraverse(struct node* root)
{
  if (root == NULL) return;
  InTraverse(root->left);
  printf("%d ", root->data);
  in_array[i]=root->data;
  i++;
  InTraverse(root->right);
}

void PrTraverse(struct node* root)
{
  if (root == NULL) return;
  printf("%d ", root->data);
  PrTraverse(root->left);
  PrTraverse(root->right);
}

void PostTraverse(struct node* root)
{
  if (root == NULL) return;
  PostTraverse(root->left);
  PostTraverse(root->right);
  printf("%d ", root->data);
}


int main()
{
    int ar[100];
    while('1')
{
    int choice;
    scanf("%d",&choice);

  struct node *root;
  int n;
  if(choice==1){
  scanf("%d",&n);


  for(int i=0;i<n;i++)
  {
      scanf("%d",&ar[i]);
  }
  root = new_node(ar[0]);
  for(int i=1;i<n;i++){
  insert(root, ar[i]);}
  }
  else if(choice==2){
  int x;
  scanf("%d",&x);
  for(int i=0;i<n;i++)
  {
      if(x==ar[i])
      {
          printf("%d \n",x);
          flag=1;
          break;
      }
  }
  if(flag==0){
    printf("-1 \n");
    printf("\n");
  }
  }
  else if(choice==3){
  InTraverse(root);
  printf("\n");}
  else if(choice==4){
  PrTraverse(root);
  printf("\n");}
  else if(choice==5){
  PostTraverse(root);
  printf("\n");}
  else if(choice==6){
  printf("%d \n",in_array[0]);}
  else if(choice==7){
  printf("%d \n",in_array[n-1]);}
  else if(choice==8){
  int k;
  scanf("%d",&k);
  printf("%d \n",in_array[k-1]);}
  else if(choice==9){
  int key;
  scanf("%d",&key);
  root=delete(root,key);
  InTraverse(root);
  printf("\n");}
  else if(choice==10)
  {
      break;
  }
  else{break;}
}
return 0;
}
