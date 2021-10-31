# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        prev = list1
        count = 0
        while count != a - 1:
            prev = prev.next
            count += 1
        next = prev.next
        while count != b:
            next = next.next
            count += 1
        prev.next = list2
        node = list2
        while node.next:
            node = node.next
        node.next = next
        return list1