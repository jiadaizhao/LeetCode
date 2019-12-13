class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        nums.append(-1)
        St = []
        total = 0
        for i, num in enumerate(nums):
            while St and num < nums[St[-1]]:
                total += i - St.pop()
            St.append(i)
        return total

class Solution2:
    def validSubarrays(self, nums: List[int]) -> int:
        St = []
        total = 0
        for num in nums:
            while St and num < St[-1]:
                St.pop()
            St.append(num)
            total += len(St)
        return total
