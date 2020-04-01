class ValidWordAbbr:
    
    def __init__(self, dictionary: List[str]):
        self.table = {}
        for word in dictionary:
            key = self.getKey(word)
            if key in self.table:
                if self.table[key] != word:
                    self.table[key] = ''
            else:
                self.table[key] = word
        

    def isUnique(self, word: str) -> bool:
        key = self.getKey(word)
        return key not in self.table or self.table[key] == word
        

    def getKey(self, s):
        if len(s) <= 2:
            return s
        return s[0] + str(len(s) - 2) + s[-1]

# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
