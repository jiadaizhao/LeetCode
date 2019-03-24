import random
class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        index = -1
        count = 0
        for i, n in enumerate(self.nums):
            if n == target:
                if random.randrange(count + 1) == 0:
                    index = i
                count += 1
        return index


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
