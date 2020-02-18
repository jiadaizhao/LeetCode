import collections
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False
        table = collections.Counter(s1)
        count = len(table)
        start = 0
        for i in range(len(s2)):
            table[s2[i]] -= 1
            if table[s2[i]] == 0:
                count -= 1
                if count == 0 and i - start + 1 == len(s1):
                    return True
                    
                while count == 0:
                    table[s2[start]] += 1
                    if table[s2[start]] == 1:
                        count += 1
                    elif i - start == len(s1):
                        return True
                    start += 1
        
        return False


class Solution2:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False
        table = collections.Counter(s1)
        count = len(s1)
        start = 0
        for i in range(len(s2)):
            table[s2[i]] -= 1
            if table[s2[i]] >= 0:
                count -= 1
                if count == 0:
                    return True
                
            if i - start + 1 == len(s1):
                table[s2[start]] += 1
                if table[s2[start]] > 0:
                    count += 1
                start += 1
        
        return False
