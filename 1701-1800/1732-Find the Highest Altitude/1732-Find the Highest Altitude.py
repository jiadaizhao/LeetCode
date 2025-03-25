class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        maxAlt = curr = 0
        for g in gain:
            curr += g
            maxAlt = max(maxAlt, curr)
        return maxAlt
