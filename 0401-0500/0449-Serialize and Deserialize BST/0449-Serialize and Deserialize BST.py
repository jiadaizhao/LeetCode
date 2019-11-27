# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return '[]'
        nodes = [root]
        i = 0
        while i < len(nodes):
            if nodes[i]:
                nodes.append(nodes[i].left)
                nodes.append(nodes[i].right)
            i += 1
        
        while nodes[-1] is None:
            nodes.pop()
            
        return '[' + ','.join(str(node.val) if node else 'null' for node in nodes) +']'
            

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == '[]':
            return None
        
        strs = data[1:-1].split(',')
        root = TreeNode(int(strs[0]))
        Q = collections.deque([root])
        leftChild = True
        for s in strs[1:]:
            if s != 'null':
                node = TreeNode(int(s))
                if leftChild:
                    Q[0].left = node
                else:
                    Q[0].right = node
                Q.append(node)
            leftChild =  not leftChild
            if leftChild:
                Q.popleft()
        return root    
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
