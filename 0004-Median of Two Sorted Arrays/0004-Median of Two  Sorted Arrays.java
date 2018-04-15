class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = iMin + (iMax - iMin) / 2;
            int j = halfLen - i;
            if (i < m && j > 0 && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            }
            else if (i > 0 && j < n && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            }
            else {
                int maxLeft;
                if (i == 0) maxLeft = nums2[j - 1];
                else if (j == 0) maxLeft = nums1[i - 1];
                else maxLeft = Math.max(nums1[i - 1], nums2[j - 1]);
                
                if ((m + n) % 2 != 0)
                    return maxLeft;
                int minRight;
                if (i == m) minRight = nums2[j];
                else if (j == n) minRight = nums1[i];
                else minRight = Math.min(nums1[i], nums2[j]);
                
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0;
    }
}
