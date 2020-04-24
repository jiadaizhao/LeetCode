# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        St = []
        head = tail = prev = None
        curr = root
        while St or curr:
            if curr:
                St.append(curr)
                curr = curr.left
            else:
                curr = St.pop()
                if prev is None:
                    head = curr
                else:
                    curr.left = prev
                    prev.right = curr
                
                tail = curr
                prev = curr
                curr = curr.right
        
        head.left = tail
        tail.right = head
        return head
