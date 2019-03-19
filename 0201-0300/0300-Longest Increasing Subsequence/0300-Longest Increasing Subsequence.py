import bisect
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0

        lis = [nums[0]]
        for num in nums[1:]:
            if num > lis[-1]:
                lis.append(num)
            else:
                index = bisect.bisect_left(lis, num)
                lis[index] = num
        return len(lis)
