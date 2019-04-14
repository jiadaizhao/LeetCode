import collections
class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """

    def generate(self, word):
        for i in range(len(word)):
            yield word[:i] + '*' + word[i+1:]
    
    
    def buildDict(self, dict: List[str]) -> None:
        """
        Build a dictionary through a list of words
        """
        self.words = set(dict)
        self.table = collections.Counter(w for word in dict for w in self.generate(word))
        

    def search(self, word: str) -> bool:
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        """
        return any(self.table[w] > 1 or self.table[w] == 1 and word not in self.words for w in self.generate(word))


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
