# Definition for a Node.
class Node:
    def __init__(self, val, left, right, parent):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent

class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Node':
        if node.right:            
            curr = node.right
            while curr.left:
                curr = curr.left
        else:
            curr = node.parent
            while curr and curr.val < node.val:
                curr = curr.parent
        return curr
