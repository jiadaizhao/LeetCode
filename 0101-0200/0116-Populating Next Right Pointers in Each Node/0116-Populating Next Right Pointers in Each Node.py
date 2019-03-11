# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        node = root
        while node:
            p = node
            while p:
                if p.left:
                    p.left.next = p.right
                if p.right and p.next:
                    p.right.next = p.next.left
                p = p.next
            node = node.left
        return root
