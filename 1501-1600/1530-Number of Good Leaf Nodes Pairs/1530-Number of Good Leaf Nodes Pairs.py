# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        total = 0
        def dfs(curr):
            result = [0] * (distance + 1)
            if curr is None:
                return result
            if curr.left is None and curr.right is None:
                result[1] = 1
                return result
            left = dfs(curr.left)
            right = dfs(curr.right)
            nonlocal total
            for i in range(1, distance):
                for j in range(distance - i, 0, -1):
                    total += left[i] * right[j]
            for i in range(2, distance):
                result[i] = left[i - 1] + right[i - 1]
            return result
        dfs(root)
        return total
