class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        table = {}
        for i, num in enumerate(nums):
            if num in table and i - table[num] <= k:
                return True
            else:
                table[num] = i
        return False
