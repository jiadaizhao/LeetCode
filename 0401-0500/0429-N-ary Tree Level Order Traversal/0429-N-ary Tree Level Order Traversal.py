# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root is None:
            return []
        level = [root]
        result = []
        while level:
            result.append([node.val for node in level])
            level = [child for node in level for child in node.children]
        return result
