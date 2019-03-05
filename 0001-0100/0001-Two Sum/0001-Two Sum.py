class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        result = [0, 0]
        for i, num in enumerate(nums):
            if target - num in table:
                result[0] = table[target - num]
                result[1] = i
                break
            else:
                table[num] = i
        return result
