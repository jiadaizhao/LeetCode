class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = [0] * (len(nums) + 1)
        self.bit = [0] * (len(nums) + 1)
        for i, val in enumerate(nums):
            self.update(i, val)

    def update(self, i: int, val: int) -> None:
        diff = val - self.nums[i]
        if diff != 0:
            self.nums[i] = val
            index = i + 1
            while index < len(self.bit):
                self.bit[index] += diff
                index += (-index) & index

    def sumRange(self, i: int, j: int) -> int:
        return self.read(j + 1) - self.read(i)

    def read(self, index):
        total = 0
        while index > 0:
            total += self.bit[index]
            index -= (-index) & index
        return total
        
# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
