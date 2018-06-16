class Solution {
public:
    int longestMountain(vector<int>& A) {
        int left = 0, maxLen = 0;
        while (left < A.size()) {
            int mid = left;
            while (mid < A.size() - 1 && A[mid + 1] > A[mid]) {
                ++mid;
            }
            if (mid == left) {
                ++left;
                continue;
            }
            
            int right = mid;
            while (right < A.size() - 1 && A[right + 1] < A[right]) {
                ++right;
            }
            if (right > mid) {
                maxLen = max(maxLen, right - left + 1);
            }
            left = right;
        }
        return maxLen;
    }
};
