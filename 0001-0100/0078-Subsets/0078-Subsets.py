class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        for i in range(1 << len(nums)):
            path = []
            for j in range(len(nums)):
                if i & (1 << j):
                    path.append(nums[j])
            result.append(path)
        return result
