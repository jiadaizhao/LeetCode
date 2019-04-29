class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int sum = 0, n = A.size();
        for (int a : A) {
            sum += a;
        }
        bool isPossible = false;
        for (int i = 1; i <= n / 2; ++i) {
            if (sum * i % n == 0) {
                isPossible = true;
                break;
            }
        }
        if (!isPossible) {
            return false;
        }
        vector<vector<bool>> dp(1 + n, vector<bool>(1 + sum));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = min(n/2, i); j > 0; --j) {
                for (int k = sum - 1; k >= A[i - 1]; --k) {
                    if (dp[j - 1][k - A[i - 1]]) {
                        dp[j][k] = true;
                    }
                }                
            }
        }
        
        for (int i = 1; i < n/2 + 1; ++i) {
            for (int j = 1; j < sum; ++j) {
                if (dp[i][j] && j * (n - i) == i * (sum - j)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int sum = 0, n = A.size();
        for (int a : A) {
            sum += a;
        }
        bool isPossible = false;
        for (int i = 1; i <= n / 2; ++i) {
            if (sum * i % n == 0) {
                isPossible = true;
                break;
            }
        }
        if (!isPossible) {
            return false;
        }
        vector<unordered_set<int>> sums(1 + n / 2);
        sums[0].insert(0);
        for (int num : A) {
            for (int i = n / 2; i >= 1; --i) {
                for (int s : sums[i - 1]) {
                    sums[i].insert(s + num);
                }
            }
        }
        
        for (int i = 1; i <= n / 2; ++i) {
            if (sum*i%n == 0 && sums[i].count(sum*i/n)) {
                return true;
            }
        }
        return false;
    }
};
