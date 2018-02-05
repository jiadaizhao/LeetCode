class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (auto mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        
        int rowHits = 0;
        int colStart = 0;
        vector<int> colHits(N);
        vector<int> rowStart(N);
        int maxLen = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (j == 0 || grid[i][j - 1] == 0) {
                    rowHits = 0;
                    colStart = j;
                    for (int k = j; k < N && grid[i][k] == 1; ++k) {
                        ++rowHits;
                    }
                }
                
                if (i == 0 || grid[i - 1][j] == 0) {
                    colHits[j] = 0;
                    rowStart[j] = i;
                    for (int k = i; k < N && grid[k][j] == 1; ++k) {
                        ++colHits[j];
                    }
                }
                
                maxLen = max(maxLen, min({j - colStart + 1, i - rowStart[j] + 1, rowHits - (j - colStart), colHits[j] - (i - rowStart[j])}));                
            }
        }
        
        return maxLen;
    }
};
