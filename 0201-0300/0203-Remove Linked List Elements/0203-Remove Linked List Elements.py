# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        p = dummy = ListNode(-1)
        while head:
            if head.val != val:
                p.next = head
                p = p.next
            head = head.next
        p.next = None
        return dummy.next
