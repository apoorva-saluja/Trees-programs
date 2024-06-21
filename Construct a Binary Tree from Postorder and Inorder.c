#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left, *right;
};


struct Node* newNode(int data);
int search(int arr[], int strt, int end, int value);

struct Node* buildUtil(int in[], int post[], int inStrt, int inEnd,
				int* pIndex)
{
	// Base case
	if (inStrt > inEnd)
		return NULL;
	struct Node* node = newNode(post[*pIndex]);
	(*pIndex)--;

	if (inStrt == inEnd)
		return node;
	int iIndex = search(in, inStrt, inEnd, node->data);
	node->right= buildUtil(in, post, iIndex + 1, inEnd, pIndex);
	node->left= buildUtil(in, post, inStrt, iIndex - 1, pIndex);

	return node;
}

struct Node* buildTree(int in[], int post[], int n)
{
	int pIndex = n - 1;
	return buildUtil(in, post, 0, n - 1, &pIndex);
}

int search(int arr[], int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++) {
		if (arr[i] == value)
			break;
	}
	return i;
}

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

void preOrder(struct Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int main()
{
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
	int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
	int n = sizeof(in) / sizeof(in[0]);
	struct Node* root = buildTree(in, post, n);
	preOrder(root);

	return 0;
}
