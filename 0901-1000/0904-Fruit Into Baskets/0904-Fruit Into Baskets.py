import collections
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        table = collections.Counter()
        types = maxCount = start = 0
        for i, t in enumerate(tree):
            table[t] += 1
            if table[t] == 1:
                types += 1
            while types > 2:
                table[tree[start]] -= 1
                if table[tree[start]] == 0:
                    types -= 1
                start += 1
            maxCount = max(maxCount, i - start + 1)
        return maxCount


class Solution2:
    def totalFruit(self, tree: List[int]) -> int:
        maxCount = count = count2 = prev1 = prev2 = 0
        for t in tree:
            if t == prev2 or t == prev1:
                count += 1
            else:
                count = count2 + 1
                
            maxCount = max(maxCount, count)    
            
            if t == prev2:
                count2 += 1
            else:
                count2 = 1
                prev1, prev2 = prev2, t
        return maxCount
