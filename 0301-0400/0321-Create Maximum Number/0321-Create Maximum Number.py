class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def reserveKDigits(nums, k):            
            count = len(nums) - k
            result = []
            for num in nums:
                while result and num > result[-1] and count > 0:
                    result.pop()
                    count -= 1
                result.append(num)
            return result[:k]
        
        maxNum = [0] * k
        for i in range(max(k - len(nums2), 0), min(len(nums1), k) + 1):
            left = reserveKDigits(nums1, i)
            right = reserveKDigits(nums2, k - i)
            maxNum = max(maxNum, [max(left, right).pop(0) for _ in left + right])
        return maxNum
