# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        pre = []
        suc = []
        def getNextPredecessor():
            curr = pre.pop()
            val = curr.val
            curr = curr.left
            while curr:
                pre.append(curr)
                curr = curr.right
            return val
        
        def getNextSuccessor():
            curr = suc.pop()
            val = curr.val
            curr = curr.right
            while curr:
                suc.append(curr)
                curr = curr.left
            return val
        
        while root:
            if root.val <= target:
                pre.append(root)
                root = root.right
            else:
                suc.append(root)
                root = root.left
        
        result = []
        for _ in range(k):
            if not pre:
                result.append(getNextSuccessor())
            elif not suc:
                result.append(getNextPredecessor())
            else:
                if target - pre[-1].val < suc[-1].val - target:
                    result.append(getNextPredecessor())
                else:
                    result.append(getNextSuccessor())
        
        return result
