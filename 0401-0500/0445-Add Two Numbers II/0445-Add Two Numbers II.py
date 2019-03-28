# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        St1 = []
        while l1:
            St1.append(l1)
            l1 = l1.next
            
        St2 = []
        while l2:
            St2.append(l2)
            l2 = l2.next
            
        carry = 0
        head = None
        while St1 or St2 or carry:
            sum = carry
            if St1:
                sum += St1.pop().val
            if St2:
                sum += St2.pop().val
            node = ListNode(sum%10)
            node.next = head
            head = node
            carry = sum // 10
        return head
