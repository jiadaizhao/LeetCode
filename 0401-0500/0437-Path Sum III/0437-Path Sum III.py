# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if root is None:
            return 0
        
        def dfs(root, sum):
            if root is None:
                return 0
            sum -= root.val
            count = 1 if sum == 0 else 0
            return dfs(root.left, sum) + dfs(root.right, sum) + count
        return self.pathSum(root.left, sum) + self.pathSum(root.right, sum) + dfs(root, sum)

import collections
class Solution2:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        table = collections.Counter([0])
        count = 0
        def dfs(root, curr):
            nonlocal count
            if root is None:
                return
            curr += root.val
            count += table[curr - sum]
            table[curr] += 1
            dfs(root.left, curr)
            dfs(root.right, curr)
            table[curr] -= 1
        dfs(root, 0)    
        return count
