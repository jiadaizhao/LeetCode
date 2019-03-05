class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        nums.sort()
        for i in range(len(nums) - 3):
            if i == 0 or nums[i] != nums[i - 1]:
                for j in range(i + 1, len(nums) - 2):
                    if j == i + 1 or nums[j] != nums[j - 1]:
                        start = j + 1
                        end = len(nums) - 1
                        while start < end:
                            if nums[i] + nums[j] + nums[start] + nums[end] == target:
                                result.append([nums[i], nums[j], nums[start], nums[end]])
                                start += 1
                                while start < end and nums[start] == nums[start - 1]:
                                    start += 1
                                end -= 1
                                while start < end and nums[end] == nums[end + 1]:
                                    end -= 1
                            elif nums[i] + nums[j] + nums[start] + nums[end] < target:
                                start += 1
                            else:
                                end -= 1
        return result
