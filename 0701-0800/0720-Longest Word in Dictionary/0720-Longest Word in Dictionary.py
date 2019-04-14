from functools import reduce
import collections
class Solution:
    def longestWord(self, words: 'List[str]') -> 'str':
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()
        END = True

        for i, word in enumerate(words):
            reduce(dict.__getitem__, word, trie)[END] = i

        St = list(trie.values())
        result = ''
        while St:
            curr = St.pop()
            if END in curr:
                word = words[curr[END]]
                if len(word) > len(result) or len(word) == len(result) and word < result:
                    result = word
                St.extend([curr[letter] for letter in curr if letter != END])

        return result

class TrieNode:
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)
        self.index = -1
        
class Solution2:
    def longestWord(self, words: List[str]) -> str:
        root = TrieNode()
        for i, word in enumerate(words):
            node = root
            for c in word:
                node = node.next[c]
            node.index = i
            
        St = list(root.next.values())
        result = ''
        while St:
            node = St.pop()
            if node.index != -1:
                word = words[node.index]
                if len(word) > len(result) or len(word) == len(result) and word < result:
                    result = word
                St.extend(node.next.values())
        return result
