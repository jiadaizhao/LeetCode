class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int low = 0, high = A.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] >= mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return A[low] == low ? low : -1;
    }
};
