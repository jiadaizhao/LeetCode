import collections
class TrieNode:
    
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.count = collections.Counter()

class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = TrieNode()
        for sentence, time in zip(sentences, times):
            self.insert(self.root, sentence, time)
        self.currNode = self.root
        self.currStr = ''
        
    def insert(self, root, sentence, time):
        for c in sentence:
            root = root.children[c]
            root.count[sentence] += time

    def input(self, c: str) -> List[str]:
        if c == '#':
            self.insert(self.root, self.currStr, 1)
            self.currNode = self.root
            self.currStr = ''
        else:
            self.currStr += c
            if self.currNode is None or c not in self.currNode.children:
                self.currNode = None
                return []
            self.currNode = self.currNode.children[c]
            pairs = sorted(self.currNode.count.items(), key=lambda x: (-x[1], x[0]))[:3]
            return [p[0] for p in pairs]


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)
