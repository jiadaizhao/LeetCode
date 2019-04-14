class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        if s % k:
            return False
        target = s // k
        maxNum = max(nums)
        if maxNum > target:
            return False

        dp = [False]*(1 << len(nums))
        dp[0] = True
        sums = [0]*(1 << len(nums))
        for i in range(len(dp)):
            if not dp[i]:
                continue
            for j in range(len(nums)):
                next = i | (1 << j)
                if next != i and not dp[next]:
                    if nums[j] <= target - sums[i] % target:
                        dp[next] = True
                        sums[next] = sums[i] + nums[j]
                    else:
                        break

        return dp[-1]
