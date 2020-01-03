# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        Q = collections.deque([(root, 0)])
        minCol = maxCol = 0
        table = collections.defaultdict(list)
        while Q:
            node, col = Q.popleft()
            minCol = min(minCol, col)
            maxCol = max(maxCol, col)
            table[col].append(node.val)
            if node.left:
                Q.append((node.left, col - 1))
            if node.right:
                Q.append((node.right, col + 1))
        return [table[col] for col in range(minCol, maxCol + 1)]
