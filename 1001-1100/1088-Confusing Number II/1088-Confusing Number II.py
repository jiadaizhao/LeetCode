class Solution:
    def confusingNumberII(self, N: int) -> int:
        table = {0:0, 1:1, 6:9, 8:8, 9:6}
        keys = [0, 1, 6, 8, 9]
        def dfs(num, rotation, base):
            count = 0
            if num != rotation:
                count += 1
            for d in keys:
                if num == 0 and d == 0:
                    continue
                if num * 10 + d > N:
                    break
                count += dfs(num * 10 + d, table[d] * base + rotation, base * 10)
            return count
        
        return dfs(0, 0, 1)
