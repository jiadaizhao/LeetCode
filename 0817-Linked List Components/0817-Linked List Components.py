# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
        table = set(G)
        curr = head
        count = 0
        while curr:
            if curr.val in table and (curr.next == None or curr.next.val not in table):
                count += 1
            curr = curr.next
        return count
