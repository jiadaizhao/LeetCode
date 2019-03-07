class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        path = []
        def dfs(start, s):
            if s == target:
                result.append(path[:])
                return
            
            for i in range(start, len(candidates)):
                if s + candidates[start] > target:
                    break
                path.append(candidates[i])
                dfs(i, s + candidates[i])
                path.pop()
        
        dfs(0, 0)
        return result
