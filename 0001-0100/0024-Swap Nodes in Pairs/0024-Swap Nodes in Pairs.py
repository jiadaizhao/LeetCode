# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = curr = ListNode(-1)
        while head and head.next:
            next = head.next.next
            curr.next = head.next
            head.next.next = head
            head.next = next
            
            curr = curr.next.next
            head = next
        curr.next = head
        return dummy.next
