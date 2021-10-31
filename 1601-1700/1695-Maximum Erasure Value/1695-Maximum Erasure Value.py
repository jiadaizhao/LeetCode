class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        maxScore = score = start = 0
        table = {}
        for i, num in enumerate(nums):       
            score += num
            while num in table and start <= table[num]:
                score -= nums[start]
                start += 1
            table[num] = i
            maxScore = max(maxScore, score)
            
        return maxScore
