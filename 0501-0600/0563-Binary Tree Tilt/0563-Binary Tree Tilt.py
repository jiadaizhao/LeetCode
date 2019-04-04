# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        total = 0
        def findSum(root):
            if root is None:
                return 0
            nonlocal total
            leftSum = findSum(root.left)
            rightSum = findSum(root.right)
            total += abs(leftSum - rightSum)
            return leftSum + root.val + rightSum
        findSum(root)
        return total
