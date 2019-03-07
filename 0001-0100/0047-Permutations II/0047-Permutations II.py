class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = []
        used = [False]*len(nums)
        path = []
        nums.sort()
        def dfs():
            if len(path) == len(nums):
                result.append(path[:])
                return
            
            for i in range(len(nums)):
                if used[i]:
                    continue
                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue
                used[i] = True
                path.append(nums[i])
                dfs()
                path.pop()
                used[i] = False
        dfs()
        return result
