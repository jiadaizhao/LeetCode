import bisect
class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        def lengthOfLIS(nums):
            lens = [1] * n
            lis = [nums[0]]
            for i in range(1, n):
                num = nums[i]
                if num > lis[-1]:
                    lis.append(num)
                    lens[i] = len(lis)
                else:
                    index = bisect.bisect_left(lis, num)
                    lis[index] = num
                    lens[i] = index + 1
            return lens
        
        l1, l2 = lengthOfLIS(nums), lengthOfLIS(nums[::-1])[::-1]
        maxLen = 0
        for i in range(n):
            if l1[i] >= 2 and l2[i] >= 2:
                maxLen = max(maxLen, l1[i] + l2[i] - 1)
                
        return n - maxLen
