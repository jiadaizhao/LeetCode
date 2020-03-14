# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        p = head
        while p:
            np = Node(p.val, p.next, p.random)
            p.next = np
            p = np.next
            
        p = head
        while p:
            if p.random:
                p.next.random = p.random.next
            p = p.next.next
            
        p = head
        nh = head.next
        while p:
            np = p.next
            p.next = np.next
            p = p.next
            if p:
                np.next = p.next
        return nh
