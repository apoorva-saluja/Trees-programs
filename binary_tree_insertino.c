#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data)
{
    // If the tree is empty, assign a new node address to the root
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else {
        // Else, do level order traversal until we find an empty
        // slot for the new node
        struct Node* temp;
        struct Node* front = NULL;
        struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));
        int rear = -1;

        // Enqueue the root
        queue[++rear] = root;

        while (rear >= 0) {
            temp = queue[0];
            front = queue[0];
            int flag = 0;

            // Dequeue the front node and enqueue its left child
            // if it exists
            if (temp->left == NULL) {
                temp->left = createNode(data);
                break;
            }
            else
                queue[++rear] = temp->left;

            // Enqueue the right child if it exists
            if (temp->right == NULL) {
                temp->right = createNode(data);
                break;
            }
            else
                queue[++rear] = temp->right;

            // Dequeue the dequeued node
            for (int i = 0; i <= rear; i++)
                queue[i] = queue[i + 1];
            rear--;
        }
        free(queue);
        return root;
    }
}

// Function to print the level order traversal of the binary tree
void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear] = root;

    while (front <= rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[++rear] = current->left;

        if (current->right != NULL)
            queue[++rear] = current->right;
    }
}

int main() {
    struct Node* root = NULL;
    int numNodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the values of the nodes: ");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}
