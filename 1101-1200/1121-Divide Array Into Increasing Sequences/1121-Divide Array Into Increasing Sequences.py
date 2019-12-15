import collections
class Solution:
    def canDivideIntoSubsequences(self, nums: List[int], K: int) -> bool:
        return len(nums) >= K * max(v for v in collections.Counter(nums).values())
