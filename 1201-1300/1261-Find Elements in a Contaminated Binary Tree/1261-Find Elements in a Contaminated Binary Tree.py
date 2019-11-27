# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class FindElements:

    def __init__(self, root: TreeNode):
        self.table = set()
        def dfs(root, curr):
            if root is None:
                return
            root.val = curr
            self.table.add(curr)
            dfs(root.left, curr * 2 + 1)
            dfs(root.right, curr * 2 + 2)
            
        dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.table


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
