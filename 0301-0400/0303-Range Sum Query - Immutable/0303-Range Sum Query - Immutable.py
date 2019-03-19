class NumArray:
    
    def __init__(self, nums: List[int]):
        self.presum = [0] * (len(nums) + 1)
        for i, num in enumerate(nums):
            self.presum[i + 1] = self.presum[i] + num

    def sumRange(self, i: int, j: int) -> int:
        return self.presum[j + 1] - self.presum[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
