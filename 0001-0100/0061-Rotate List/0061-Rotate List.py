# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None:
            return head
        l = 1
        tail = head
        while tail.next:
            tail = tail.next
            l += 1
        k %= l
        p = head
        for _ in range(l - 1 - k):
            p = p.next
        tail.next = head
        head = p.next
        p.next = None
        return head
