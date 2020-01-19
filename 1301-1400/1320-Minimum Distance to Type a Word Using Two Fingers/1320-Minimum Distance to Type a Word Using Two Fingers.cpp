class Solution {
public:
    int minimumDistance(string word) {
        int dp[2][26][26] = {0};
        int minDist = INT_MAX;
        for (int k = word.size() - 1; k >= 0; --k) {
            int target = word[k] - 'A';
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    dp[k & 1][i][j] = min(dp[(k + 1) & 1][target][j] + dist(i, target), dp[(k + 1) & 1][i][target] + dist(j, target));
                    if (k == 0) {
                        minDist = min(minDist, dp[0][i][j]);
                    }
                }
            }
        }
        
        return minDist;
    }
    
private:
    int dist(int source, int target) {
        return abs(source / 6 - target / 6) + abs(source % 6 - target % 6);
    }
};


class Solution2 {
public:
    int minimumDistance(string word) {
        vector<int> dp(26);
        int total = 0, save = 0;
        for (int i = 0; i < word.size() - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            int orig = dist(b, c);
            total += orig;
            for (int a = 0; a < 26; ++a) {
                dp[b] = max(dp[b], dp[a] + orig - dist(a, c));
                save = max(save, dp[b]);
            }
        }
        
        return total - save;
    }
    
private:
    int dist(int source, int target) {
        return abs(source / 6 - target / 6) + abs(source % 6 - target % 6);
    }
};
