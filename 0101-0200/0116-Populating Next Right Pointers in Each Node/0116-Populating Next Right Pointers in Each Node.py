# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        curr = root
        while curr:
            p = curr
            while p:
                if p.left:
                    p.left.next = p.right
                    if p.next:
                        p.right.next = p.next.left
                p = p.next
            curr = curr.left
        return root
