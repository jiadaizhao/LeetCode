# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if root is None:
            return []
        St = [root]
        result = []
        while St:
            node = St.pop()
            result.append(node.val)
            St += node.children
        return result[::-1]
