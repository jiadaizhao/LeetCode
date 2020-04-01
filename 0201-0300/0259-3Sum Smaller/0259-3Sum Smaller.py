class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        nums.sort()
        count = 0
        for i in range(len(nums) - 2):
            start = i + 1
            end = len(nums) - 1
            t = target - nums[i]
            while start < end:
                if nums[start] + nums[end] < t:
                    count += end - start
                    start += 1
                else:
                    end -= 1
        return count
