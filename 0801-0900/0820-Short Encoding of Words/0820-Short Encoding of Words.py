import collections
from functools import reduce

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        table = set(words)
        for word in words:
            for i in range(1, len(word)):
                table.discard(word[i:])

        return sum(len(word) + 1 for word in table)

class Solution:
    def minimumLengthEncoding(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        words = list(set(words))
        #Trie is a nested dictionary with nodes created
        # when fetched entries are missing
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()

        #reduce(..., S, trie) is trie[S[0]][S[1]][S[2]][...][S[S.length - 1]]
        nodes = [reduce(dict.__getitem__, word[::-1], trie)
                 for word in words]

        #Add word to the answer if it's node has no neighbors
        return sum(len(word) + 1
                   for i, word in enumerate(words)
                   if len(nodes[i]) == 0)

class TrieNode:
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)

class Solution3:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        root = TrieNode()
        table = []
        for word in set(words):
            node = root
            for c in word[::-1]:
                node = node.next[c]
            table.append((node, len(word) + 1))
        return sum(l for node, l in table if not node.next)
