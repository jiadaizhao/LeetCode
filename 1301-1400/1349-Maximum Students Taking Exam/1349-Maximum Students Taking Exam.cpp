class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<int> mask(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    mask[i] |= (1 << j);
                }
            }
        }
        vector<int> dp(1 << n);
        int maxNum = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> temp(1 << n);
            for (int j = 0; j < dp.size(); ++j) {
                if ((j & mask[i]) == j && !(j & (j >> 1))) {
                    for (int k = 0; k < dp.size(); ++k) {
                        if (!(j & (k >> 1)) && !((j >> 1) & k)) {
                            temp[j] = max(temp[j], dp[k] + __builtin_popcount(j));
                            maxNum = max(maxNum, temp[j]);
                        }
                    }
                }
            }
            dp = std::move(temp);
        }
        
        return maxNum;
    }
};
