# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        le = 0
        head = root
        while head:
            le += 1
            head = head.next
        count, remain = divmod(le, k)
        result = [None] * k
        head = root
        prev = None
        for i in range(k):
            if head is None:
                break
            else:
                result[i] = head
            for j in range(count):
                prev = head
                head = head.next
            if remain > 0:
                prev = head
                head = head.next
                remain -= 1
            prev.next = None
        return result
