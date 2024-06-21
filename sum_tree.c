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
int sum(struct node *root)
{
    if(root==NULL)return 0;
    else
        return sum(root->left)+root->data+sum(root->right);
}

int isSumTree(struct node *root)
{
    if(root==NULL || ((root->left==NULL)&&(root->right==NULL)))
       return 1;
    else
    {
        int ls=sum(root->left);
        int rs=sum(root->right);
        if((root->data==ls+rs)&&((isSumTree(root->left))&&(isSumTree(root->right))))
           return 1;
    }
    return 0;
}

int CheckIfNodesAreSiblings(struct node* root, int data_one,int data_two)
{
    if (!root)
        return 0;

    if (root->left && root->right)
    {
        int left = root->left->data;
        int right = root->right->data;

        if (left == data_one && right == data_two)
            return 1;
        else if (left == data_two && right == data_one)
            return 1;
    }
    if (root->left)
        if(CheckIfNodesAreSiblings(root->left, data_one,data_two))
          return 1;

    if (root->right)
        if(CheckIfNodesAreSiblings(root->right, data_one,data_two))
          return 1;
}

int main()
{
	struct node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->right->left = createnode(5);
    root->right->right = createnode(6);
    root->left->left->right = createnode(7);

    int data_one = 4;
    int data_two = 6;

    if (CheckIfNodesAreSiblings(root, data_one, data_two))
        printf("YES \n");
    else
        printf("NO \n");
	if(isSumTree(root))
		printf("The given tree is a SumTree.");
	else
		printf("The given tree is not a SumTree.");

	return 0;
}
/*

int isSumTree(struct node* node)
{
	int ls, rs;
	if(node == NULL ||(node->left == NULL && node->right == NULL))
		return 1;

ls = sum(node->left);
rs = sum(node->right);

	if((node->data == ls + rs)&&
			isSumTree(node->left) &&
			isSumTree(node->right))
		return 1;

return 0;
}

*/
