class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        result = []
        for left, right in zip(l, r):
            a = sorted(nums[left : right + 1])
            for i in range(2, len(a)):
                if a[i] - a[i - 1] != a[1] - a[0]:
                    result.append(False)
                    break
            else:
                result.append(True)
        return result
