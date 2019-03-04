class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m, n = len(nums1), len(nums2)
        if (m > n):
            return self.findMedianSortedArrays(nums2, nums1)
        iMin, iMax, halfLen = 0, m, (m + n + 1) // 2
        while iMin <= iMax:
            i = iMin + (iMax - iMin) // 2
            j = halfLen - i
            if i < m and j > 0 and nums2[j - 1] > nums1[i]:
                iMin = i + 1
            elif i > 0 and j < n and nums1[i - 1] > nums2[j]:
                iMax = i - 1
            else :
                if (i == 0):
                    maxLeft = nums2[j - 1]
                elif j == 0:
                    maxLeft = nums1[i - 1]
                else:
                    maxLeft = max(nums1[i - 1], nums2[j - 1])
                
                if ((m + n) % 2 != 0):
                    return maxLeft
                if i == m:
                    minRight = nums2[j]
                elif j == n:
                    minRight = nums1[i]
                else:
                    minRight = min(nums1[i], nums2[j])
                
                return (maxLeft + minRight) / 2
        return 0
