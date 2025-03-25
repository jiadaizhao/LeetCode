class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        jobs.sort(reverse=True)
        n = len(jobs)
        def dfs(curr, limit):
            if curr == n:
                return True
            for i in range(k):
                if cap[i] >= jobs[curr]:
                    cap[i] -= jobs[curr]
                    if dfs(curr + 1, limit):
                        return True
                    cap[i] += jobs[curr]
                if cap[i] == limit:
                    break
            return False
        
        left = max(jobs)
        right = sum(jobs)
        while left < right:
            mid = (left + right) // 2
            cap = [mid] * k 
            if dfs(0, mid):
                right = mid
            else:
                left = mid + 1
        return left
