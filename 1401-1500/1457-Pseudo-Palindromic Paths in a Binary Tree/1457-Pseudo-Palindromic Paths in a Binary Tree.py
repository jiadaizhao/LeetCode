# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        def dfs(curr, parity):
            if curr is None:
                return 0
            parity ^= (1 << curr.val)
            result = 0
            if curr.left is None and curr.right is None:
                if parity & (parity - 1) == 0:
                    result += 1
            else:
                result += dfs(curr.left, parity) + dfs(curr.right, parity)
            return result

        return dfs(root, 0)
