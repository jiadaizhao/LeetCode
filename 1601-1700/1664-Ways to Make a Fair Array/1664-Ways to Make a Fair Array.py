class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        right = [0] * 2
        for i, num in enumerate(nums):
            right[i & 1] += num
        result = 0
        even = odd = 0
        for i, num in enumerate(nums):
            right[i & 1] -= num
            if even + right[1] == odd + right[0]:
                result += 1
            if i & 1:
                odd += num
            else:
                even += num
        return result
