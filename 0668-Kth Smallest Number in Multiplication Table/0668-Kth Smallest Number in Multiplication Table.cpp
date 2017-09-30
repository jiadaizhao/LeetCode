class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if (m > n) {
            swap(m, n);
        }
        int start = 1, end = m * n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }
            
            if (count < k) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        return start;
    }
};
