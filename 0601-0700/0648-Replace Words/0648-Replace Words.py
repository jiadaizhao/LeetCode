import collections
class TrieNode:
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)
        self.word = ''

class Solution:
    def replaceWords(self, dict: 'List[str]', sentence: 'str') -> 'str':
        root = TrieNode()
        for word in dict:
            node = root
            for c in word:
                node = node.next[c]
            node.word = word
            
        def findRoot(word):
            node = root
            for c in word:
                if c not in node.next:
                    break
                node = node.next[c]
                if node.word:
                    return node.word
            return word
        
        return ' '.join(map(findRoot, sentence.split()))
