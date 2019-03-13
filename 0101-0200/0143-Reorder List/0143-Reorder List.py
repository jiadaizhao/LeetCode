# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None:
            return
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        head2 = slow.next
        curr = head2
        prev = None
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        head2 = prev
        slow.next = None
        
        p1 = head
        p2 = head2
        while p1 and p2:
            next2 = p2.next
            p2.next = p1.next
            p1.next = p2
            p1 = p2.next
            p2 = next2
