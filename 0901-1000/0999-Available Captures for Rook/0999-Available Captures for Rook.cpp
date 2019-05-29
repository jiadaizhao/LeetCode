class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    int count = 0;
                    for (int k = 0; k < 4; ++k) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        while (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && board[nr][nc] != 'B') {
                            if (board[nr][nc] == 'p') {
                                ++count;
                                break;
                            }
                            nr += dr[k];
                            nc += dc[k];
                        }
                    }
                    return count;
                }
            }
        }

        return 0;
    }
};
