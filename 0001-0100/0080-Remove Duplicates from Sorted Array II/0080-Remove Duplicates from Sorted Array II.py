class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 0
        duplicate = False
        for num in nums:
            if count == 0 or num != nums[count - 1]:
                duplicate = False
                nums[count] = num
                count += 1
            elif not duplicate:
                duplicate = True
                nums[count] = num
                count += 1
        return count

class Solution2:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 0
        for num in nums:
            if count < 2 or num > nums[count - 2]:
                nums[count] = num
                count += 1
        return count
