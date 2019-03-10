# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n <= 0:
            return []
        table = {}
        def dfs(start, end):
            if start > end:
                return [None]
            if (start, end) in table:
                return table[(start, end)]
            result = []
            for i in range(start, end+1):
                for left in dfs(start, i - 1):
                    for right in dfs(i + 1, end):
                        root = TreeNode(i)
                        root.left = left
                        root.right = right
                        result.append(root)
            table[(start, end)] = result
            return result
        return dfs(1, n)