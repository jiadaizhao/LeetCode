class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: x[1])
        prev = pairs[0][1]
        maxLen = 1
        for s, e in pairs[1:]:
            if s > prev:
                maxLen += 1
                prev = e
        
        return maxLen
