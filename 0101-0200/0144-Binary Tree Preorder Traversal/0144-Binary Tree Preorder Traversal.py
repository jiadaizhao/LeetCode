# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        St = [root]
        result = []
        while St:
            root = St.pop()
            result.append(root.val)
            if root.right:
                St.append(root.right)
            if root.left:
                St.append(root.left)
        return result

class Solution2:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        curr = root
        while curr:
            if curr.left is None:
                result.append(curr.val)
                curr = curr.right
            else:
                prev = curr.left
                while prev.right and prev.right != curr:
                    prev = prev.right
                if prev.right is None:
                    result.append(curr.val)
                    prev.right = curr
                    curr = curr.left
                else:
                    prev.right = None
                    curr = curr.right
        return result
