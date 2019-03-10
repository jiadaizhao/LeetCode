# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        result = []
        level = [root]
        while level:
            result.append([node.val for node in level])
            level = [child for node in level for child in (node.left, node.right) if child]
        return result[::-1]
