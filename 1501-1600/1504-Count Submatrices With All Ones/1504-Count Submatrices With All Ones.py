class Solution:
    def numSubmat(self, mat):
        m, n = len(mat), len(mat[0])
        total = 0
        heights = [0] * n
        for i in range(m):
            St = []
            dp = [0] * (n)
            for j in range(n):
                if mat[i][j] == 1:
                    heights[j] += 1
                else:
                    heights[j] = 0
                while St and heights[St[-1]] >= heights[j]:
                    St.pop()
                if St:
                    prevIndex = St[-1]
                    dp[j] = dp[prevIndex] + heights[j] * (j - prevIndex)
                else:
                    dp[j] = heights[j] * (j + 1)
                St.append(j)
            total += sum(dp)
        return total
