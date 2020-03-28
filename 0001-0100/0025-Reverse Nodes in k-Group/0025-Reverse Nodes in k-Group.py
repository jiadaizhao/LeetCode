# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        def reverseNextK(head, k):
            tail = curr = head.next
            for _ in range(k):
                if tail is None:
                    return None
                tail = tail.next
            head.next = reverseList(curr, tail)
            return curr
        
        def reverseList(head, tail):
            curr = head
            prev = tail
            while curr != tail:
                next = curr.next
                curr.next = prev
                prev = curr
                curr = next
            return prev
        
        p = dummy = ListNode(-1)
        p.next = head
        while p:
            p = reverseNextK(p, k)
        return dummy.next
