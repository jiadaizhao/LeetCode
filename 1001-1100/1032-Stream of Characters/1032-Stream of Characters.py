import collections

class TrieNode:
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)
        self.isEnd = False


class StreamChecker:
    
    def __init__(self, words: List[str]):
        self.root = TrieNode()
        self.history = []
        self.maxLen = 0
        for word in words:
            node = self.root
            self.maxLen = max(self.maxLen, len(word))
            for c in word[::-1]:
                node = node.next[c]
            node.isEnd = True

    def query(self, letter: str) -> bool:
        self.history = ([letter] + self.history)[:self.maxLen]
        node = self.root
        for c in self.history:
            if c not in node.next:
                return False
            node = node.next[c]
            if node.isEnd:
                return True

        return False


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
