// C program to check if a tree is height-balanced or not */
#include <stdio.h>
#include <stdlib.h>
#define bool int

// Structure of a tree node
struct node {
	int data;
	struct node* left;
	struct node* right;
};

// Function to create a new tree Node
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Functio to check if tree is height balanced
int isBalanced(struct node* root)
{
	if (root == NULL)
		return 0;
	int lh = isBalanced(root->left);
	if (lh == -1)
		return -1;
	int rh = isBalanced(root->right);
	if (rh == -1)
		return -1;

	if (abs(lh - rh) > 1)
		return -1;
	else
		return lh > rh ? lh + 1 : rh + 1;
}

// Driver code
int main()
{
	int height = 0;

	struct node* root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(30);
	root->right->left = newNode(15);
	root->right->right = newNode(20);

	if (isBalanced(root) > 0)
		printf("\nBalanced\n");
	else
		printf("\nNot Balanced\n");

	// getchar();
	return 0;
}