# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if head is None:
            return head
        curr = head
        while curr:
            if curr.child:
                tail = curr.child
                while tail.next:
                    tail = tail.next
                tail.next = curr.next
                if curr.next:
                    curr.next.prev = tail
                    
                curr.next = curr.child
                curr.child.prev = curr
                curr.child = None
            curr = curr.next
        return head
