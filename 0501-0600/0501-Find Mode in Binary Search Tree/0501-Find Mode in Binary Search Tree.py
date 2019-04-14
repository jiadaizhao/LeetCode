# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        maxCount = modeCount = currVal = currCount = 0
        result = []
        def handleVal(val):
            nonlocal maxCount, modeCount, currVal, currCount 
            if currVal != val:
                currVal = val
                currCount = 1
            else:
                currCount += 1
            if currCount > maxCount:
                maxCount = currCount
                modeCount = 1
            elif currCount == maxCount:
                modeCount += 1
                if result:
                    result[modeCount - 1] = val
                
        def inorder(root):
            if root is None:
                return
            inorder(root.left)
            handleVal(root.val)
            inorder(root.right)
            
        inorder(root)
        result = [0]*modeCount
        currCount = modeCount = 0
        inorder(root)
        return result

class Solution2:
    def findMode(self, root: TreeNode) -> List[int]:
        maxCount = currVal = currCount = 0
        result = []               
                
        def inorder(root):
            if root is None:
                return
            inorder(root.left)
            nonlocal maxCount, currVal, currCount 
            if currVal != root.val:
                currVal = root.val
                currCount = 1
            else:
                currCount += 1
            if currCount > maxCount:
                maxCount = currCount
                result.clear()
                result.append(root.val)
            elif currCount == maxCount:
                result.append(root.val)
            inorder(root.right)
            
        inorder(root)
        return result
