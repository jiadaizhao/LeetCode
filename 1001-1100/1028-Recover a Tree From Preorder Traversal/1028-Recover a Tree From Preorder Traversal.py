# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        i = 0
        while i < len(S) and S[i] != '-':
            i += 1
        root = TreeNode(int(S[:i]))
        table = {0: root}
        prev = 0
        while i < len(S):
            start = i
            while i < len(S) and S[i] == '-':
                i += 1
            curr = i - start
            start = i
            while i < len(S) and S[i] != '-':
                i += 1
            node = TreeNode(int(S[start : i]))
            if curr == prev + 1:
                table[curr - 1].left = node
            else:
                table[curr - 1].right = node
            table[curr] = node
            prev = curr
        return root                
