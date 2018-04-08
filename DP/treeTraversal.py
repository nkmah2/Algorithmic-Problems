# Tree Traversal - PreOder, PostOrder and InOrder

class Node:
    def __init__(self, data):
        self.right = None
        self.left = None
        self.data = data
        
        
#    1
#   / \
#  2   3
# /\    \
#4  5    6


root = Node(1)
root.left = Node(2)
root.left.left = Node(4)
root.left.right = Node(5)
root.right = Node(3)
root.right.right = Node(6)

def preOrder(root):
    if root != None:
        print root.data,
        preOrder(root.left)
        preOrder(root.right)
    
def postOrder(root):
    if root != None:
        postOrder(root.left)
        postOrder(root.right)
        print root.data,
        
def InOrder(root):
    if root != None:
        InOrder(root.left)
        print root.data,
        InOrder(root.right)
        
preOrder(root)
print
postOrder(root)
print
InOrder(root)
