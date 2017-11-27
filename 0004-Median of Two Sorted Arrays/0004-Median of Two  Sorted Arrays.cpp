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
