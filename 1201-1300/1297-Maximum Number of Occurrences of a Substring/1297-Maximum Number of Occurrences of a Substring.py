import collections
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        table = collections.Counter()
        letter = start = maxCount = 0
        count = collections.Counter()
        for i, c in enumerate(s):
            table[c] += 1
            if table[c] == 1:
                letter += 1
            if i - start + 1 > minSize:
                table[s[start]] -= 1
                if table[s[start]] == 0:
                    letter -= 1
                start += 1
            if i - start + 1 == minSize and letter <= maxLetters:
                count[s[start: i+1]] += 1
                maxCount = max(maxCount, count[s[start: i+1]])

        return maxCount
