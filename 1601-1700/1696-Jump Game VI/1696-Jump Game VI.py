import collections
class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        maxScore = 0
        dq = collections.deque()
        n = len(nums)
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            while dq and dq[0] > i + k:
                dq.popleft()
            maxScore = nums[i] + (dp[dq[0]] if dq else 0)
            dp[i] = maxScore
            while dq and maxScore > dp[dq[-1]]:
                dq.pop()
            dq.append(i)
        return maxScore
