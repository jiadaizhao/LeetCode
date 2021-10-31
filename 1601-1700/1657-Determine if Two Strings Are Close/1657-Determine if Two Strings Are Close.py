import collections
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool: 
        set1 = set(word1)
        set2 = set(word2)
        if set1 != set2:
            return False
        table1 = collections.Counter(word1)
        table2 = collections.Counter(word2)
        return sorted(table1.values()) == sorted(table2.values())
