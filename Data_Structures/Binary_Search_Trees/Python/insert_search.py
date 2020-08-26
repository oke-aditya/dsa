# Simple BST in python

class Node(object):
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
        
# Search for value in BST
def search(root : Node, key):
    if root is None or root.val == key:
        return root
    elif key > root.val:
        return search(root.right, key)
    else:
        return search(root.left, key)

def insert(root : Node, node : Node):
    if root is None:
        root = node
    else:
        if node.val > root.val:
            if root.right is None:
                root.right = node
            else:
                insert(root.right, node)

        else:
            if root.left is None:
                root.left = node
            else:
                insert(root.left, node)

def inorder(root : Node):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)

if __name__ == "__main__":
    # Let us create the following BST 
    #      50 
    #    /      \ 
    #   30     70 
    #   / \    / \ 
    #  20 40  60 80 
    #     
    
    r = Node(50)
    insert(r,Node(30)) 
    insert(r,Node(20)) 
    insert(r,Node(40)) 
    insert(r,Node(70)) 
    insert(r,Node(60)) 
    insert(r,Node(80)) 

    inorder(r)
    
