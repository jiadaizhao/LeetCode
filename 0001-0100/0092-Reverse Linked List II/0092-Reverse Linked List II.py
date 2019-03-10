# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        p = dummy = ListNode(-1)
        p.next = head
        for _ in range(m - 1):
            p = p.next
        curr = p.next
        prev = None
        for _ in range(n - m + 1):
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        p.next.next = curr
        p.next = prev
        return dummy.next
