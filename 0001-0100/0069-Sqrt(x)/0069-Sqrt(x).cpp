class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x, result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid <= x / mid) {
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;      
    }
};

