class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        path = []
        def dfs(start, s):
            if s == target:
                result.append(path[:])
                return
            
            for i in range(start, len(candidates)):
                if s + candidates[i] > target:
                    break
                    
                if i == start or candidates[i] != candidates[i - 1]:
                    path.append(candidates[i])
                    dfs(i + 1, s + candidates[i])
                    path.pop()
        dfs(0, 0)
        return result
