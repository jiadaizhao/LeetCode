class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N));
        dp[r][c] = 1;
        vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
        vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};
        for (int k = 0; k < K; ++k) {
            vector<vector<double>> temp(N, vector<double>(N));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (int l = 0; l < dx.size(); ++l) {
                        int nx = i + dx[l];
                        int ny = j + dy[l];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                            temp[i][j] += dp[nx][ny] / 8;
                        }
                    }
                }
            }
            dp = temp;
        }
        
        double sum = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                sum += dp[i][j];
            }
        }
        
        return sum;
    }
};
