/*
Why Trees?
1. One reason to use trees might be because you want to store information that naturally forms a hierarchy. For example, the file system on a computer: 
2. Trees (with some ordering e.g., BST) provide moderate access/search (quicker than Linked List and slower than arrays).
3. Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
4. Like Linked Lists and unlike Arrays, Trees don’t have an upper limit on number of nodes as nodes are linked using pointers.

Binary Tree Representation in C: A tree is represented by a pointer to the topmost node in tree. If the tree is empty, then value of root is NULL.
A Tree node contains following parts.
1. Data
2. Pointer to left child
3. Pointer to right child

*/

#include<stdio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int new_data)
{
	struct node* new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = new_data; 
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node)
	
}

int main()
{
	// create the root
	struct node *root = newnode(1);
	/* following is the tree after above statement  
  
        1 
      /   \ 
     NULL  NULL   
  */
	root->left = newnode(2)
	root->right = newnode(3)
	/* 2 and 3 become left and right children of 1 
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */

	root->left->left = newnode(4);
	/* 4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/

	return(0);
}


