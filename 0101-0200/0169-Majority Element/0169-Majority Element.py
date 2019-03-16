class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 1
        candidate = nums[0]
        for num in nums[1:]:
            if num == candidate:
                count += 1
            else:
                count -= 1
                if count == 0:
                    count = 1
                    candidate = num
        return candidate
