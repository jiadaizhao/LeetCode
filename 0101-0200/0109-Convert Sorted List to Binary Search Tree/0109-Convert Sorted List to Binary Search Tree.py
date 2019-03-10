# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        curr = head
        l = 0
        while curr:
            l += 1
            curr = curr.next

        def dfs(l):
            nonlocal head
            if l == 0:
                return None
            left = dfs(l // 2)
            root = TreeNode(head.val)
            root.left = left
            head = head.next
            root.right = dfs(l - l // 2 - 1)
            return root
        
        return dfs(l)
