class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        
        vector<int> deltaX = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> deltaY = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                for (int k = 0; k < deltaX.size(); ++k) {
                    int ni = i + deltaX[k];
                    int nj = j + deltaY[k];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (board[ni][nj] & 1) {
                            ++count;
                        }
                    }
                }
                
                if (board[i][j] & 1) {
                    if (count == 2 || count == 3) {
                        board[i][j] |= 2;
                    }
                }
                else if (count == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
