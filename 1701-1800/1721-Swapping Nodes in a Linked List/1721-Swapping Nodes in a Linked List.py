# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        curr = head
        n1 = n2 = None
        while curr:
            if n2:
                n2 = n2.next
            k -= 1
            if k == 0:
                n1 = curr
                n2 = head
            curr = curr.next
        n1.val, n2.val = n2.val, n1.val
        return head
