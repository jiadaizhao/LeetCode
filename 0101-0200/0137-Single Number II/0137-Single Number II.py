class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for i in range(32):
            result += (sum((num >> i)&1 for num in nums) % 3) << i
        return result - (1 << 32) if result >= (1 << 31) else result

class Solution2:
    def singleNumber(self, nums: List[int]) -> int:
        one = two = 0
        for num in nums:
            one = (one ^ num) & (~two)
            two = (~one) & (two ^ num)
        return one
