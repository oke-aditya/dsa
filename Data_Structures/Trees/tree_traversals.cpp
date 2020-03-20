#include<iostream>
using namespace std;

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


struct node
{
	int data;
	struct node *left;
	struct node *right;
	
	node(int data)
	{
		this->data = data;
		right = NULL;
		left = NULL;
	}
};

void printpostorder(struct node *newnode)
{
	if(newnode == NULL)
		return;
	printpostorder(newnode->left);
	printpostorder(newnode->right);
	cout<<newnode->data<<" ";
}

void printpreorder(struct node *newnode)
{
	if(newnode == NULL)
		return;
	
	cout<<newnode->data<<" ";
	printpreorder(newnode->left);
	printpreorder(newnode->right);
}

void printinorder(struct node *newnode)
{
	if(newnode == NULL)
		return;
	printinorder(newnode->left);
	cout<<newnode->data<<" ";
	printinorder(newnode->right);
}

int main()
{
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
		
	cout<<endl<<"Print Preorder traversal of binary tree "<<endl;
	printpreorder(root);
	
	cout<<endl<<"Print Inorder traversal of binary tree"<<endl;
	printinorder(root);
	
	cout<<endl<<"Print Postorder traversal of binary tree"<<endl;
	printpostorder(root);
	
	return(0);
}


