# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        self.St = []
        while root:
            self.St.append(root)
            root = root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        node = self.St.pop()
        result = node.val
        node = node.right
        while node:
            self.St.append(node)
            node = node.left
        return result
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.St) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
