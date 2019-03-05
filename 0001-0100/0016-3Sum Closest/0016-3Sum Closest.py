class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closestSum = sum(nums[:3])
        for i in range(len(nums) - 2):
            if i == 0 or nums[i] != nums[i - 1]:
                start = i + 1
                end = len(nums) - 1
                while start < end:
                    s = nums[i] + nums[start] + nums[end]
                    if s < target:
                        if target - s < abs(target - closestSum):
                            closestSum = s
                        start += 1
                    elif s > target:
                        if s - target < abs(target - closestSum):
                            closestSum = s
                        end -= 1
                    else:
                        return target
        return closestSum
