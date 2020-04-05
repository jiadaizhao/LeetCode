class Solution:
    def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
        left, right = 0, len(nums) - 1
        result = [0] * len(nums)
        def quad(x):
            return a * x * x + b * x + c
        index = len(nums) - 1 if a >= 0 else 0
        if a >= 0:
            while left <= right:
                l = quad(nums[left])
                r = quad(nums[right])
                if l > r:
                    result[index] = l
                    index -= 1
                    left += 1
                else:
                    result[index] = r
                    index -= 1
                    right -= 1
        else:
            while left <= right:
                l = quad(nums[left])
                r = quad(nums[right])
                if l <= r:
                    result[index] = l
                    index += 1
                    left += 1
                else:
                    result[index] = r
                    index += 1
                    right -= 1
        
        return result
