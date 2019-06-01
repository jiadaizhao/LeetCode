# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
            
        result = [0] * len(vals)
        St = []
        for i in range(len(vals) - 1, -1, -1):
            while St and St[-1] <= vals[i]:
                St.pop()
            if St:
                result[i] = St[-1]
            St.append(vals[i])

        return result
