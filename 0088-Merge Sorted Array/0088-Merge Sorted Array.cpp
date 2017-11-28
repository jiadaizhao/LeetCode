class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        else if (m == 0) {
            for (int i = 0; i < n; ++i) {
                nums1[i] = nums2[i];
            }
            
            return;
        }
        
        int end1 = m - 1, end2 = n - 1;
        int end = m + n - 1;
        while (end1 >= 0 && end2 >= 0) {
            if (nums1[end1] <= nums2[end2]) {
                nums1[end] = nums2[end2--];
            }
            else {
                nums1[end] = nums1[end1--];
            }
            --end;
        }
        
        while (end2 >= 0) {
            nums1[end--] = nums2[end2--];
        }
    }
};
