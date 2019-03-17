import collections
class TrieNode:
    
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.word = ''

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for word in words:
            node = root
            for c in word:
                node = node.children[c]
            node.word = word
        
        result = []
        def dfs(i, j, node):
            c = board[i][j]
            if c == '#' or c not in node.children:
                return
            node = node.children[c]
            if node.word != '':
                result.append(node.word)
                node.word = ''
                
            board[i][j] = '#'
            if i > 0:
                dfs(i - 1, j, node)
            if i < len(board) - 1:
                dfs(i + 1, j, node)
            if j > 0:
                dfs(i, j - 1, node)
            if j < len(board[0]) - 1:
                dfs(i, j + 1, node)
            board[i][j] = c
            
        for i in range(len(board)):
            for j in range(len(board[0])):
                dfs(i, j, root)

        return result
