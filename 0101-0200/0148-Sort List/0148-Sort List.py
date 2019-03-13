# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        right = self.sortList(slow.next)
        slow.next = None
        left = self.sortList(head)
        def merge(l1, l2):
            p = dummy = ListNode(-1)
            while l1 and l2:
                if l1.val <= l2.val:
                    p.next = l1
                    l1 = l1.next
                else:
                    p.next = l2
                    l2 = l2.next
                p = p.next
            p.next = l1 if l1 else l2
            return dummy.next
        
        return merge(left, right)
            
class Solution2:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        curr = head
        l = 0
        while curr:
            l += 1
            curr = curr.next
            
        def split(head, n):
            if head is None:
                return None
            for _ in range(n - 1):
                if head.next is None:
                    return None
                head = head.next
            second = head.next
            head.next = None
            return second
        
        def merge(l1, l2, head):
            p = head
            while l1 and l2:
                if l1.val <= l2.val:
                    p.next = l1
                    l1 = l1.next
                else:
                    p.next = l2
                    l2 = l2.next
                p = p.next
            p.next = l1 if l1 else l2
            while p.next:
                p = p.next
            return p
          
        tail = dummy = ListNode(-1)
        dummy.next = head
        step = 1
        while step < l:
            curr = dummy.next
            tail = dummy
            while curr:
                left = curr
                right = split(left, step)
                curr = split(right, step)
                tail = merge(left, right, tail)
            step <<= 1
        
        return dummy.next
