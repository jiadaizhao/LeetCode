class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        zero = [0] * m
        for i in range(m):
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 0:
                    zero[i] += 1
                else:
                    break
        
        count = 0
        for i in range(m):
            if zero[i] < n - 1 - i:
                j = i + 1
                while j < n and zero[j] < n - 1 - i:
                    j += 1
                if j == n:
                    return -1
                while j > i:
                    zero[j], zero[j - 1] = zero[j - 1], zero[j]
                    j -= 1
                    count += 1
        return count
