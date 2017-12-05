class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            curr += i * A[i];
        }

        int maxVal = curr;
        for (int k = 1; k < n; ++k) {
            curr += sum - n * A[n - k];
            maxVal = max(maxVal, curr);
        }
        
        return maxVal;
    }
};
