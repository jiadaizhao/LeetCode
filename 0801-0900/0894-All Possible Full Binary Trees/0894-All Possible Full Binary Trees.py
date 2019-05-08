# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    memo = {0: [], 1: [TreeNode(0)]}
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        if N not in Solution.memo:
            result = []
            for i in range(1, N, 2):
                lefts = self.allPossibleFBT(i)
                rights = self.allPossibleFBT(N - 1 - i)
                for left in lefts:
                    for right in rights:
                        root = TreeNode(0)
                        root.left = left
                        root.right = right
                        result.append(root)
            Solution.memo[N] = result
        return Solution.memo[N]
