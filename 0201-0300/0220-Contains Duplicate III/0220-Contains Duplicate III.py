class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t < 0 or k <= 0:
            return False
        table = {}
        w = 1 + t
        for i, num in enumerate(nums):
            curr = num // w
            if curr in table:
                return True
            if curr - 1 in table and num - table[curr - 1] <= t:
                return True
            if curr + 1 in table and table[curr + 1] - num <= t:
                return True
            table[curr] = num
            if i >= k:
                del table[nums[i - k] // w]
        return False
