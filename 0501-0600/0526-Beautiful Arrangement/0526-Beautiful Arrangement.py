class Solution:
    def countArrangement(self, N: int) -> int:
        used = [0] * (N + 1)
        count = 0
        def dfs(start):
            nonlocal count
            if start == 0:
                count += 1
                return
            
            for i in range(N, 0, -1):
                if (not used[i]) and (i % start == 0 or start % i == 0):
                    used[i] = 1
                    dfs(start - 1)
                    used[i] = 0
                    
        dfs(N)
        return count


class Solution2:
    def countArrangement(self, N: int) -> int:
        nums = [i for i in range(1 + N)]
        count = 0
        def dfs(start):
            nonlocal count
            if start == 0:
                count += 1
                return
            
            for i in range(start, 0, -1):
                nums[i], nums[start] = nums[start], nums[i]
                if nums[start] % start == 0 or start % nums[start] == 0:
                    dfs(start - 1)
                nums[i], nums[start] = nums[start], nums[i]
                    
        dfs(N)
        return count
