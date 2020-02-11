import collections
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        table = collections.Counter(arr)
        minSize = count = 0
        for k in sorted(table, key=lambda x: table[x], reverse=True):
            count += table[k]
            minSize += 1
            if count >= len(arr) // 2:
                break
        return minSize
