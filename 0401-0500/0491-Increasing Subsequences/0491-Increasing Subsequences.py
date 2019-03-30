class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        path = []
        result = []
        def dfs(start):
            if len(path) >= 2:
                result.append(path[:])
            used = set()
            for i in range(start, len(nums)):
                if nums[i] not in used and (not path or nums[i] >= path[-1]):
                    path.append(nums[i])
                    used.add(nums[i])
                    dfs(i + 1)
                    path.pop()
        dfs(0)
        return result
