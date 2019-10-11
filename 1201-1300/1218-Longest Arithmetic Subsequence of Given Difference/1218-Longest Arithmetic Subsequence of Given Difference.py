import collections
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        table = collections.Counter()
        maxLen = 0
        for a  in arr:
            table[a] = table[a - diff] + 1
            maxLen = max(maxLen, table[a])
        
        return maxLen
