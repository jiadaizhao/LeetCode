import collections
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        table = collections.defaultdict(lambda : collections.defaultdict(list))
        def dfs(node, x, y):
            if node:
                table[x][y].append(node.val)
                dfs(node.left, x - 1, y + 1)
                dfs(node.right, x + 1, y + 1)
                
        dfs(root, 0, 0)
        result = []
        for x in sorted(table):
            col = []
            for y in sorted(table[x]):
                col.extend(sorted(val for val in table[x][y]))
            result.append(col)
        return result
