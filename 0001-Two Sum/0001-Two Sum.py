class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        result = [0] * 2
        for i, num in enumerate(nums):
            if target - num in d:
                result[0] = d[target - num]
                result[1] = i
                break
            else:
                d[num] = i
        return result
