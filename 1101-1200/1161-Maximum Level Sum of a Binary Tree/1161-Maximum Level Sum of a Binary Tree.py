# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        maxSum = root.val
        maxLeval = 1
        Q = collections.deque([root])
        level = 0
        while Q:
            s = 0
            for _ in range(len(Q)):
                node = Q.popleft()
                s += node.val
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
            
            level += 1
            if s > maxSum:
                maxSum = s
                maxLeval = level
        
        return maxLeval
