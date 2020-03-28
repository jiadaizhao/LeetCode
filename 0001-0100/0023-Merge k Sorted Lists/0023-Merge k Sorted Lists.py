# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        interval = 1
        def mergeTwoLists(l1, l2):
            dummy = curr = ListNode(-1)
            while l1 and l2:
                if l1.val <= l2.val:
                    curr.next = l1
                    l1 = l1.next
                else:
                    curr.next = l2
                    l2 = l2.next
                curr = curr.next
            curr.next = l1 or l2
            return dummy.next
                
        while interval < len(lists):
            for i in range(0, len(lists) - interval, interval*2):
                lists[i] = mergeTwoLists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if lists else None

import heapq
class Solution2:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        pq = [(head.val, i, head) for i, head in enumerate(lists) if head]
        heapq.heapify(pq)
        dummy = curr = ListNode(-1)
        while pq:
            i, curr.next = heapq.heappop(pq)[1:3]
            curr = curr.next
            if curr.next:
                heapq.heappush(pq, (curr.next.val, i, curr.next))
        return dummy.next
