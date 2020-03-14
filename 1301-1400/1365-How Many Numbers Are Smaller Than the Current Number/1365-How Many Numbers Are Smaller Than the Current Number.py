class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        presum = [0] * 101
        for num in nums:
            presum[num] += 1
        for i in range(1, 101):
            presum[i] += presum[i - 1]
        
        return [presum[num - 1] if num > 0 else 0 for num in nums]
