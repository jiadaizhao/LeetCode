import collections
class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dp = nums[:]
        dq = collections.deque()
        for i, num in enumerate(nums):
            dp[i] += dq[0] if dq else 0
            while dq and dp[i] >= dq[-1]:
                dq.pop()
            if dp[i] > 0:
                dq.append(dp[i])
            if i >= k and dq and dq[0] == dp[i - k]:
                dq.popleft()
                              
        return max(dp)


# Put index indstead of value in deque
import collections
class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dp = nums[:]
        dq = collections.deque()
        for i, num in enumerate(nums):
            dp[i] += dp[dq[0]] if dq else 0
            while dq and dp[i] >= dp[dq[-1]]:
                dq.pop()
            if dp[i] > 0:
                dq.append(i)
            if dq and dq[0] <= i - k:
                dq.popleft()
                     
        return max(dp)
