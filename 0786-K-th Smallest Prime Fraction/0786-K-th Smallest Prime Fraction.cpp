class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        double low = 0, high = 1;
        int total = n * (n - 1) / 2;
        double err = 1e-8;
        while (high - low > err) {
            double mid = (low + high) / 2;
            int count = 0, left = 0;
            for (int right = 1; right < n; ++right) {
                while (A[left] <= mid * A[right]) {
                    ++left;
                }
                count += right - left;
            }

            if (total - count >= K) {
                high = mid;
            }
            else {
                low = mid;
            }
        }

        // cout << low << endl;
        vector<int> result(2);
        int count = 0, left = 0;
        for (int right = 1; right < n; ++right) {
            while (A[left] <= (low - err) * A[right]) {
                ++left;
            }
            
            if (A[left] < (low + err) * A[right]) {
                result[0] = A[left];
                result[1] = A[right];
                break;
            }
        }
        return result;
    }
};
