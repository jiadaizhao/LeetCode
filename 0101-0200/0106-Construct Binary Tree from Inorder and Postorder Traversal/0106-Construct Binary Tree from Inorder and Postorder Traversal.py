# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        table = {value:index for index, value in enumerate(inorder)}
        postIndex = len(postorder) - 1
        def dfs(inStart, inEnd):
            nonlocal postIndex
            if inStart > inEnd:
                return None
            root = TreeNode(postorder[postIndex])
            postIndex -= 1
            index = table[root.val]
            root.right = dfs(index + 1, inEnd)
            root.left = dfs(inStart, index - 1)
            return root
        return dfs(0, len(inorder) - 1)
