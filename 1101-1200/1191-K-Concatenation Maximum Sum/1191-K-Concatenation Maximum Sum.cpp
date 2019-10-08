class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long total = accumulate(arr.begin(), arr.end(), 0);
        int MOD = 1e9 + 7;
        if (k > 1) {
            arr.insert(arr.end(), arr.begin(), arr.end());
            return (max(total, 0L) * (k - 2) + kadane(arr)) % MOD;
        }
        else {
            return kadane(arr) % MOD;
        }
    }

private:
    long kadane(vector<int>& arr) {
        long sum = 0, maxSum = 0;
        for (int a : arr) {
            if (sum < 0) {
                sum = 0;
            }
            sum += a;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
