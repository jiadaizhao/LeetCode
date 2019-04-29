# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        table = set(G)
        curr = head
        count = 0
        while curr:
            if curr.val in table and (curr.next is None or curr.next.val not in table):
                count += 1
            curr = curr.next
        return count
