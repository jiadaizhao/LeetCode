class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        snums = sorted(nums, reverse=True)
        rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + list(map(str, range(4, len(nums) + 1)))
        return list(map(dict(zip(snums, rank)).get, nums))
