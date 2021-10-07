class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        i = j = sum1 = sum2 = 0
        while i < m or j < n:
            if i < m and (j == n or nums1[i] < nums2[j]):
                sum1 += nums1[i]
                i += 1
            elif j < n and (i == m or nums1[i] > nums2[j]):
                sum2 += nums2[j]
                j += 1
            else:
                sum1 = sum2 = max(sum1, sum2) + nums1[i]
                i += 1
                j += 1
        return max(sum1, sum2) % (10**9 + 7)
