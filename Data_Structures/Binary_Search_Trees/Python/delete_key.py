# Delete a value from BST

# 1) Node to be deleted is leaf: Simply remove from the tree. 
# 2) Node to be deleted has only one child: Copy the child to the node and delete the child 
# 3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the 
#  inorder successor to the node and delete the inorder successor. 
#  Note that inorder predecessor can also be used.

class Node(object):
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


# Inorder traversal
def inorder(root : Node):
    if root is not None:
        inorder(root.left)
        print(root.val)
        inorder(root.right)

# Insert into BST
def insert(node: Node, key):
    # Tree is empty return a new Node
    if node is None:
        return Node(key)
    
    # Otherwise recur
    if key > node.val:
        node.right = insert(node.right, key)
    else:
        node.left = insert(node.left, key)

    return node

# Given a non-empty binary search tree, return the node 
# with minum key value found in that tree. Note that the 
# entire tree does not need to be searched  

def minNode(node : Node):
    current = node
    # Recur left
    while(current.left is not None):
        current = current.left

    return current

# Delete the node
def deleteNode(root : Node, key):
    if root is None:
        return root
    
    # If key is smaller, recur left for deletion
    if key < root.val:
        root.left = deleteNode(root.left, key)
    
    # Key is greater
    elif key > root.val:
        root.right = deleteNode(root.right, key)
    
    # Key is root key
    else:
        # Node with only one child or no child 
        if root.left is None:
            temp = root.right
            root = None
            return temp
        
        elif root.right is None:
            temp = root.left
            root = None
            return temp

        # Node with two children: Get the inorder successor 
        # (smallest in the right subtree) 
        temp = minNode(root.right)

        # Copy inorder successor to this node
        root.val = temp.key

        # Delete inorder sucessor
        root.right = deleteNode(root.right , temp.key)
    
    return root

if __name__ == "__main__":
    root = None
    root = insert(root, 50) 
    root = insert(root, 30) 
    root = insert(root, 20) 
    root = insert(root, 40) 
    root = insert(root, 70) 
    root = insert(root, 60) 
    root = insert(root, 80) 
    
    print("Inorder traversal of the given tree")
    inorder(root) 
        
    print("\nDelete 20")
    root = deleteNode(root, 20) 
    print("Inorder traversal of the modified tree")
    inorder(root) 
    
    print("\nDelete 30")
    root = deleteNode(root, 30) 
    print("Inorder traversal of the modified tree")
    inorder(root) 

        
    print("\nDelete 50")
    root = deleteNode(root, 50) 
    print("Inorder traversal of the modified tree")
    inorder(root) 
