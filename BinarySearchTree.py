#create the node class for the binary tree
class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
    
    #insertion function for node
    def insert(self, data):
        if data < self.data:
            if self.left:
                # if we still need to move towards the left subtree
                self.left.insert(data)
            else:
                self.left = Node(data)
                return
        # if value is greater than the value of the parent node        
        else:
            if self.right:
                # if we still need to move towards the right subtree
                self.right.insert(data)
            else:
                self.right = Node(data)
                return
    
    def inorder(self):
        if self.left:
            self.left.inorder()
        print(self.data, end = " ")
        if self.right:
            self.right.inorder()

node_values = [8901,2,3,4,5,6,7,82,95,110,11,152,13,14,16]
root = Node(node_values[0])

for i in node_values[1:]:
    root.insert(i)
root.inorder()