class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> presum(1 + A.size());
        for (int i = 0; i < A.size(); ++i) {
            presum[i + 1] = presum[i] + A[i]; 
        }

        int sumL = presum[L], sumM = presum[M], maxSum = presum[L + M];
        for (int i = L + M; i < A.size(); ++i) {
            sumL = max(sumL, presum[i - M + 1] - presum[i - M - L + 1]);
            sumM = max(sumM, presum[i - L + 1] - presum[i - L - M + 1]);
            maxSum = max({maxSum, sumM + presum[i + 1] - presum[i - L + 1], sumL + presum[i + 1] - presum[i - M + 1]});
        }

        return maxSum;
    }
};
