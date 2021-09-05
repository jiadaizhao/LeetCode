class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        lastOne = -1
        for i, num in enumerate(nums):
            if num == 1:
                if lastOne != -1 and i - lastOne - 1 < k:
                    return False
                lastOne = i
        
        return True
