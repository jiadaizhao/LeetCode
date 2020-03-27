class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for num, i in zip(nums, index):
            target.insert(i, num)
        return target
