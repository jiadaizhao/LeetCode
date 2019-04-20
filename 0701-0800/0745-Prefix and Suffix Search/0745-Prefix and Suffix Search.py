import collections
class TrieNode:
    
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)
        self.weight = -1

class WordFilter:

    def __init__(self, words: List[str]):
        self.root = TrieNode()
        for weight, word in enumerate(words):
            word += '#'
            for i in range(len(word)):
                node = self.root
                for j in range(i, len(word)*2 - 1):
                    node = node.next[word[j % len(word)]]
                    node.weight = weight

    def f(self, prefix: str, suffix: str) -> int:
        node = self.root
        for c in suffix + '#' + prefix:
            if c not in node.next:
                return -1
            node = node.next[c]
        return node.weight


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
