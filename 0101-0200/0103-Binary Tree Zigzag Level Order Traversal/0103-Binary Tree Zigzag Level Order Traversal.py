# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        result = []
        level = [root]
        flag = 1
        while level:
            result.append([node.val for node in level][::flag])
            level = [child for node in level for child in (node.left, node.right) if child]
            flag *= -1 
        return result
