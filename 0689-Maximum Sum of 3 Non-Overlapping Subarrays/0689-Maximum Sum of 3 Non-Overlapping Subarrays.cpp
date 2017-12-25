class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> windows(n - k + 1);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (i >= k) {
                sum -= nums[i - k];
            }
            if (i >= k - 1) {
                windows[i - k + 1] = sum;
            }
        }
        
        vector<int> left(n - k + 1);
        int maxIndex = 0;
        for (int i = 0; i < left.size(); ++i) {
            if (windows[i] > windows[maxIndex]) {
                maxIndex = i;
            }
            left[i] = maxIndex;
        }
        
        vector<int> right(n - k + 1);
        maxIndex = n - k;
        for (int i = n - k; i >= 0; --i) {
            if (windows[i] > windows[maxIndex]) {
                maxIndex = i;
            }
            right[i] = maxIndex;
        }
        
        vector<int> index(3);
        int maxSum = INT_MIN;
        for (int i = k; i < n - 2 * k + 1; ++i) {
            int curr = windows[left[i - k]] + windows[i] + windows[right[i + k]];
            if (curr > maxSum) {
                index[0] = left[i - k];
                index[1] = i;
                index[2] = right[i + k];
                maxSum = curr;
            }
        }
        
        return index;
    }
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n + 1);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        
        vector<vector<int>> dp(4, vector<int>(1 + n));
        vector<vector<int>> index(4, vector<int>(1 + n));
        for (int i = 1; i <= 3; ++i) {
            dp[i][k * i] = presum[k * i];
            index[i][k * i] = k * i - k;
            for (int j = k * i + 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1];
                index[i][j] = index[i][j - 1];
                int curr = dp[i - 1][j - k] + presum[j] - presum[j - k];
                if (curr > dp[i][j]) {
                    dp[i][j] = curr;
                    index[i][j] = j - k;
                }
            }            
        }
        
        vector<int> result(3);
        result[2] = index[3][n];
        result[1] = index[2][result[2]];
        result[0] = index[1][result[1]];
        
        return result;      
    }
};
