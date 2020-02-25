# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Codec:

    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        if root is None:
            return '[]'
        result = ['[', str(root.val)]
        for child in root.children:
            result.append(self.serialize(child))
        result.append(']')
        return ''.join(result)

    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        if data == '[]':
            return None
        i = 1
        num = 0
        while i < len(data) - 1 and data[i].isdigit():
            num = num * 10 + int(data[i])
            i += 1
        node = Node(num, [])
        St = []
        while i < len(data) - 1:
            if data[i] == '[':
                St.append(node)
                i += 1
                num = 0
                while i < len(data) - 1 and data[i].isdigit():
                    num = num * 10 + int(data[i])
                    i += 1
                node = Node(num, [])
            elif data[i] == ']':
                i += 1
                St[-1].children.append(node)
                node = St.pop()
                
        return node

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
