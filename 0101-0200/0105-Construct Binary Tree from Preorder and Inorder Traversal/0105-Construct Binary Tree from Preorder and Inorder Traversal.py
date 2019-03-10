# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        table = {val:index for index, val in enumerate(inorder)}
        preIndex = 0
        def dfs(inStart, inEnd):
            nonlocal preIndex
            if inStart > inEnd:
                return None
            root = TreeNode(preorder[preIndex])
            preIndex += 1
            index = table[root.val]
            root.left = dfs(inStart, index - 1)
            root.right = dfs(index + 1, inEnd)
            return root
        return dfs(0, len(inorder) - 1)
