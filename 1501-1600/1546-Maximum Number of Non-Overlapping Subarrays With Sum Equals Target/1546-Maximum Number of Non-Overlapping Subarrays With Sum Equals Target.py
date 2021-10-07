class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        presum = count = 0
        table = set([0])
        for i, num in enumerate(nums):
            presum += num
            if presum - target in table:
                count += 1
                table = set([0])
                presum = 0
            else:
                table.add(presum)
        return count
