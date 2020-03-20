#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node * newnode = (struct node *) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return(node);	
}


/*
Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
   
Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree)
   
Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.

*/

void printpreorder(struct node *node)
{
	if(node == NULL)
		return;
	printpreorder(node->left);
	printf("%d ", node->data);
	printpreorder(node->right);
}

void printpostorder(struct node *node)
{
	if(node == NULL)
		return;
	printpostorder(node->left);
	printpostorder(node->right);
	printf("%d ",node->data);
}

void printinorder(struct node *node)
{
	if(node == NULL)
		return;
	
	printf("%d ",node->data);
	printinorder(node->left);
	printinorder(node->right);
}

void main()
{
	struct node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	
	printinorder(root);
	printpostorder(root);
	printpreorder(root);
	
	return(0);
}




