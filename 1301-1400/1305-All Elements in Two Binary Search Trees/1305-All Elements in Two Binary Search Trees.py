# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def pushLeft(St, node):
            if node:
                St.append(node)
                pushLeft(St, node.left)

        St1 = []
        St2 = []
        pushLeft(St1, root1)
        pushLeft(St2, root2)
        result = []
        while St1 or St2:
            St = St1 if not St2 or (St1 and St1[-1].val <= St2[-1].val) else St2
            result.append(St[-1].val)
            node = St.pop()
            pushLeft(St, node.right)
        return result
