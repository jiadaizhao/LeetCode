# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = TreeNode(preorder[0])
        St = [root]
        for val in preorder[1:]:
            node = TreeNode(val)
            prev = None
            while St and node.val > St[-1].val:
                prev = St.pop()
            if prev:
                prev.right = node
            if St and St[-1].left is None:
                St[-1].left = node
            St.append(node)
        return root
