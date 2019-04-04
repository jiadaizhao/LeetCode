class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        presum = 0
        table = {0:-1}
        for i, num in enumerate(nums):
            presum += num
            if k != 0:
                presum %= k
            if presum in table:
                if i - table[presum] > 1:
                    return True
            else:
                table[presum] = i
        return False
