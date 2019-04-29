import re
import collections
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        ban = set(banned)
        words = re.findall(r'\w+', paragraph.lower())
        maxCount = 0
        table = collections.Counter()
        for word in words:
            if word not in ban:
                table[word] += 1
                if table[word] > maxCount:
                    maxCount = table[word]
                    result = word

        return result
