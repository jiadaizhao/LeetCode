class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        rem = sum(nums) % p
        minLen = len(nums)
        table = {0 : -1}
        curr = 0
        for i, num in enumerate(nums):
            curr = (curr + num) % p
            target = (curr - rem) % p
            table[curr] = i
            if target in table:
                minLen = min(minLen, i - table[target])
            
        return minLen if minLen != len(nums) else -1
