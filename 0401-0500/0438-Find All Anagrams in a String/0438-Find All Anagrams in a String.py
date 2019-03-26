import collections
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        table = collections.Counter(p)
        count = len(p)
        start = 0
        result = []
        for i in range(len(s)):
            table[s[i]] -= 1
            if table[s[i]] >= 0:
                count -= 1
                if count == 0:
                    result.append(start)
                    
            if i - start + 1 == len(p):
                table[s[start]] += 1
                if table[s[start]] > 0:
                    count += 1
                start += 1
        return result
