# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        sentinel = ListNode(0)
        sentinel.next = head
        lastNodeNot9 = sentinel
        while head:
            if head.val != 9:
                lastNodeNot9 = head
            head = head.next
        lastNodeNot9.val += 1
        node = lastNodeNot9.next
        while node:
            node.val = 0
            node = node.next
        return sentinel if sentinel.val else sentinel.next
