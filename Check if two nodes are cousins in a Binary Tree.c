#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node *newNode(int item)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

bool isSibling(struct Node *root, int x, int y)
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

int level(struct Node *root, int ptr, int lev)
{
	if (root == NULL) return 0;
	if (root->data == ptr) return lev;
	int l = level(root->left, ptr, lev+1);
	if (l != 0) return l;
	return level(root->right, ptr, lev+1);
}


int isCousin(struct Node *root, int a, int b )
{
	if ((level(root,a,1) == level(root,b,1)) && !(isSibling(root,a,b)))
		return 1;
	else return 0;
}

int main()
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right = newNode(15);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	int Node1,Node2;
	Node1 = 1;
	Node2 = 7;

	isCousin(root,Node1,Node2)? puts("Yes"): puts("No");

	return 0;
}
