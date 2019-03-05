class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        for i in range(len(nums) - 2):
            if i == 0 or nums[i] != nums[i - 1]:
                start = i + 1
                end = len(nums) - 1
                while start < end:
                    if nums[start] + nums[end] == -nums[i]:
                        result.append([nums[i], nums[start], nums[end]])
                        start += 1
                        while start < end and nums[start] == nums[start - 1]:
                            start += 1
                        end -= 1
                        while start < end and nums[end] == nums[end + 1]:
                            end -= 1
                    elif nums[start] + nums[end] < -nums[i]:
                        start += 1
                    else:
                        end -= 1
        return result
