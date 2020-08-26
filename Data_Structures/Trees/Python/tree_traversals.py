
# Algorithm Inorder(tree)
#    1. Traverse the left subtree, i.e., call Inorder(left-subtree)
#    2. Visit the root.
#    3. Traverse the right subtree, i.e., call Inorder(right-subtree)
   
# Algorithm Preorder(tree)
#    1. Visit the root.
#    2. Traverse the left subtree, i.e., call Preorder(left-subtree)
#    3. Traverse the right subtree, i.e., call Preorder(right-subtree)
   
# Algorithm Postorder(tree)
#    1. Traverse the left subtree, i.e., call Postorder(left-subtree)
#    2. Traverse the right subtree, i.e., call Postorder(right-subtree)
#    3. Visit the root.


class Node(object):
	def __init__(self, key):
		self.left = None
		self.right = None
		self.val = key


def printinorder(root : Node):
	if root:
		printinorder(root.left)

		print(root.val)

		printinorder(root.right)

def printpostorder(root : Node):
	if root:
		printpostorder(root.left)

		printpostorder(root.right)

		print(root.val)

def printpreorder(root : Node):
	if root:
		print(root.val)

		printpreorder(root.left)

		printpreorder(root.right)

if __name__ == "__main__":
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)

	print("Preorder traversal of binary tree is")
	printPreorder(root) 
	
	print("Inorder traversal of binary tree is")
	printInorder(root) 
	
	print("Postorder traversal of binary tree is")
	printPostorder(root) 


