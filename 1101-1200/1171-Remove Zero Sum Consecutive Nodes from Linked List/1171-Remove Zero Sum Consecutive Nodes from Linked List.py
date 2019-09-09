# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        curr = dummy
        dummy.next = head
        s = 0
        table = {}
        while curr:
            s += curr.val
            if s in table:
                next = table[s].next
                temp = s + next.val
                while temp != s:
                    del table[temp]
                    next = next.next
                    temp += next.val
                table[s].next = curr.next
            else:
                table[s] = curr
            curr = curr.next
        return dummy.next
