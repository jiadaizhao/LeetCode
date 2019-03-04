// Time complexity: O(log(m + n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num = nums1.size() + nums2.size();
        if (num % 2) {
            return findKth(nums1, 0, nums2, 0, num / 2 + 1);
        }
        else {
            int ans1 = findKth(nums1, 0, nums2, 0, num / 2);
            int ans2 = findKth(nums1, 0, nums2, 0, num / 2 + 1);
            return (ans1 + ans2) / 2.0;
        }
        
    }

private:
    int findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
        if (start1 >= nums1.size()) {
            return nums2[start2 + k - 1];
        }
        else if (start2 >= nums2.size()) {
            return nums1[start1 + k - 1];
        }
        
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        
        int key1 = (start1 + k / 2 <= nums1.size()) ? nums1[start1 + k / 2 - 1] : INT_MAX;
        int key2 = (start2 + k / 2 <= nums2.size()) ? nums2[start2 + k / 2 - 1] : INT_MAX;
        if (key1 < key2) {
            return findKth(nums1, start1 + k / 2, nums2, start2, k - k / 2);
        }
        else {
            return findKth(nums1, start1, nums2, start2 + k / 2, k - k / 2); 
        }
    }
};

// Time complexity: O(log(min(m, n)))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < m && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            }
            else if (i > 0 && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            }
            else {
                int maxLeft;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0) {
                    maxLeft = nums1[i - 1];
                }
                else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }
                int minRight;
                if (i == m) {
                    minRight = nums2[j];
                }
                else if (j == n) {
                    minRight = nums1[i];
                }
                else {
                    minRight = min(nums1[i], nums2[j]);
                }

                return (maxLeft + minRight) / 2.0;
            }
        }
        
        return 0;
    }
};
