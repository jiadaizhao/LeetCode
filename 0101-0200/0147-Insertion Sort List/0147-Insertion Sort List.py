# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        prev = dummy = ListNode(-1)
        curr = head
        while curr:
            next = curr.next
            if not prev.next or prev.next.val > curr.val:
                prev = dummy

            while prev.next and prev.next.val <= curr.val:
                prev = prev.next

            curr.next = prev.next
            prev.next = curr
            curr = next

        return dummy.next
