import math
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[0]*n for i in range(n)]
        maxVal = [[0]*n for i in range(n)]
        for i in range(n):
            localMax = arr[i]
            for j in range(i, n):
                localMax = max(localMax, arr[j])
                maxVal[i][j] = localMax
        
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = math.inf
                for k in range(i, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxVal[i][k] * maxVal[k + 1][j])
        
        return dp[0][n - 1]


class Solution2:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        minSum = 0
        St = [math.inf]
        for a in arr:
            while St[-1] <= a:
                curr = St.pop()
                minSum += curr * min(St[-1], a)
            St.append(a)
            
        for i in range(2, len(St)):
            minSum += St[i] * St[i - 1]
        return minSum
