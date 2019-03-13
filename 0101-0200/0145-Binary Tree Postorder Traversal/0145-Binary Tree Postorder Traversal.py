# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        result = []
        St = [root]
        prev = None
        while St:
            curr = St[-1]
            if prev is None or prev.left == curr or prev.right == curr:
                if curr.left:
                    St.append(curr.left)
                elif curr.right:
                    St.append(curr.right)
            elif curr.left == prev:
                if curr.right:
                    St.append(curr.right)
            else:
                result.append(curr.val)
                St.pop()
            prev = curr
        return result

class Solution2:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        curr = root
        while curr:
            if curr.right is None:
                result.append(curr.val)
                curr = curr.left
            else:
                prev = curr.right
                while prev.left and prev.left != curr:
                    prev = prev.left
                if prev.left is None:
                    result.append(curr.val)
                    prev.left = curr
                    curr = curr.right
                else:
                    prev.left = None
                    curr = curr.left
        return result[::-1]
