# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class CBTInserter:

    def __init__(self, root: TreeNode):
        self.nodes = [root]
        for node in self.nodes:
            if node.left:
                self.nodes.append(node.left)
            if node.right:
                self.nodes.append(node.right)

    def insert(self, v: int) -> int:
        node = TreeNode(v)
        self.nodes.append(node)
        parent = self.nodes[len(self.nodes) // 2 - 1]
        if len(self.nodes) & 1:
            parent.right = node
        else:
            parent.left = node
        return parent.val

    def get_root(self) -> TreeNode:
        return self.nodes[0]


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
