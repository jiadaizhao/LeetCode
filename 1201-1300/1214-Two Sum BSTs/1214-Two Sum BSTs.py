# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        St1 = []
        St2 = []
        node1, node2 = root1, root2
        while node1:
            St1.append(node1)
            node1 = node1.left
        while node2:
            St2.append(node2)
            node2 = node2.right
        while St1 and St2:
            node1 = St1[-1]
            node2 = St2[-1]
            if node1.val + node2.val < target:
                St1.pop()
                node1 = node1.right
                while node1:
                    St1.append(node1)
                    node1 = node1.left
            elif node1.val + node2.val > target:
                St2.pop()
                node2 = node2.left
                while node2:
                    St2.append(node2)
                    node2 = node2.right
            else:
                return True
        return False
