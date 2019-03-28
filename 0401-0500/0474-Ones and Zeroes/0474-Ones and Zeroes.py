class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0]*(1 + n) for _ in range(1 + m)]
        for s in strs:
            count0 = count1 = 0
            for c in s:
                if c == '0':
                    count0 += 1
                else:
                    count1 += 1
            for i in range(m, count0 - 1, -1):
                for j in range(n, count1 - 1, -1):
                    dp[i][j] = max(dp[i][j], 1 + dp[i - count0][j - count1])
        return dp[m][n]
