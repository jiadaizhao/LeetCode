class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        path = []
        def dfs(start):
            result.append(path[:])
            for i in range(start, len(nums)):
                if i == start or nums[i] != nums[i - 1]:
                    path.append(nums[i])
                    dfs(i + 1)
                    path.pop()
        dfs(0)
        return result
