class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX = 0, countO = 0;
        vector<int> rows(3), cols(3);
        int diag = 0, antidiag = 0;
        bool winX = false, winO = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    ++countX;
                    ++rows[i];
                    ++cols[j];
                    if (i == j) {
                        ++diag;
                    }
                    if (i + j == 2) {
                        ++antidiag;
                    }
                }
                else if (board[i][j] == 'O') {
                    ++countO;
                    --rows[i];
                    --cols[j];
                    if (i == j) {
                        --diag;
                    }
                    if (i + j == 2) {
                        --antidiag;
                    }
                }
            }
        }
        if (countO > countX || countX - countO > 1) {
            return false;
        }
        
        if (rows[0] == 3 || rows[1] == 3 || rows[2] == 3 || cols[0] == 3 || cols[0] == 3 || cols[1] == 3 || cols[2] == 3 || diag == 3 || antidiag == 3) {
            winX = true;
        }
        if (rows[0] == -3 || rows[1] == -3 || rows[2] == -3 || cols[0] == -3 || cols[0] == -3 || cols[1] == -3 || cols[2] == -3 || diag == -3 || antidiag == -3) {
            winO = true;
        }
        
        if (winX) {
            if (winO) return false;
            if (countX == countO) return false;
        }
        else if (winO && countX > countO) {
            return false;
        }
        return true;
    }
};
