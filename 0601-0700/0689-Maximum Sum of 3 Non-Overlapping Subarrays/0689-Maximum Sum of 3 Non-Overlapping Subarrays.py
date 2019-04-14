class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        presum = [0] * (1 + n)
        for i in range(1, 1 + n):
            presum[i] = presum[i - 1] + nums[i - 1]
        dp = [[0] * (1 + n) for i in range(4)]
        index = [[0] * (1 + n) for i in range(4)]
        
        for i in range(1, 4):
            dp[i][i * k] = presum[i * k]
            index[i][i * k] = k * i - k
            for j in range(k * i + 1, n + 1):
                dp[i][j] = dp[i][j - 1]
                index[i][j] = index[i][j - 1]
                curr = dp[i - 1][j - k] + presum[j] - presum[j - k]
                if curr > dp[i][j]:
                    dp[i][j] = curr
                    index[i][j] = j - k
                    
        result = [0] * 3
        currIndex = n
        for i in range(2, -1, -1):
            result[i] = index[i + 1][currIndex]
            currIndex = result[i]
        return result
