import collections
class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isEnd = False

class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        root = TrieNode()
        for word in words:
            curr = root
            for c in word:
                curr = curr.children[c]
            curr.isEnd = True
            
        result = []
        for i in range(len(text)):
            j = i
            curr = root
            while j < len(text) and text[j] in curr.children:
                curr = curr.children[text[j]]
                if curr.isEnd:
                    result.append([i, j])
                j += 1
        return result
