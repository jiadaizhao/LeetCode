class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        nums = [(a, i) for i, a in enumerate(arr)]
        result = [0] * len(arr)
        nums.sort()
        rank = 1
        i = 0
        while i < len(nums):
            j = i
            while j < len(nums) and nums[j][0] == nums[i][0]:
                result[nums[j][1]] = rank
                j += 1
            rank += 1
            i = j
        return result
