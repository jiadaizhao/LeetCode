class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return [num for p in zip(nums[:n], nums[n:]) for num in p]
