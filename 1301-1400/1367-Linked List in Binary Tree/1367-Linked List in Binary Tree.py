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
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if root is None:
            return False
        def dfs(head, root):
            if head is None:
                return True
            if root is None:
                return False
            if head.val != root.val:
                return False
            return dfs(head.next, root.left) or dfs(head.next, root.right)
        return dfs(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)


class Solution2:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        lps = [0]
        vals = [head.val]
        l = 0
        node = head.next
        while node:
            while l and node.val != vals[l]:
                l = lps[l - 1]
            l += head.val == vals[l]
            lps.append(l)
            vals.append(node.val)            
            node = node.next

        def dfs(root, l):
            if root is None:
                return False
            while l and root.val != vals[l]:
                l = lps[l - 1]
            l += root.val == vals[l]
            if l == len(vals):
                return True
            return dfs(root.left, l) or dfs(root.right, l)
        return dfs(root, 0)
