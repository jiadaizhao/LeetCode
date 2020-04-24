import collections
class TrieNode:
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)
        self.prefix = []

class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        root = TrieNode()
        n = len(words[0])
        for word in words:
            node = root
            for c in word:
                node = node.next[c]
                node.prefix.append(word)
        result = []
        path = []
        def search(s):
            node = root
            for c in s:
                if c not in node.next:
                    return []
                node = node.next[c]
            return node.prefix
        
        def dfs():
            if len(path) == len(path[0]):
                result.append(path[:])
                return

            s = [path[i][len(path)] for i in range(len(path))]
            candidates = search(s)
            for s in candidates:
                path.append(s)
                dfs()
                path.pop()

        for word in words:
            path.append(word)
            dfs()
            path.pop()

        return result
