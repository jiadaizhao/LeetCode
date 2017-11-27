class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
    
private:
    bool helper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                
                for (char v = '1'; v <= '9'; ++v) {
                    if (isValid(board, i, j, v)) {
                        board[i][j] = v;
                        if (helper(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int r, int c, char v) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][c] == v) {
                return false;
            }
        }
        
        for (int j = 0; j < 9; ++j) {
            if (board[r][j] == v) {
                return false;
            }
        }
        
        for (int i = r / 3 * 3; i < (r / 3 + 1) * 3; ++i) {
            for (int j = c / 3 * 3; j < (c / 3 + 1) * 3; ++j) {
                if (board[i][j] == v) {
                    return false;
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        usedRows = vector<vector<bool>>(9, vector<bool>(9));
        usedCols = vector<vector<bool>>(9, vector<bool>(9));
        usedBlocks = vector<vector<bool>>(9, vector<bool>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    usedRows[i][index] = usedCols[j][index] = usedBlocks[k][index] = true;
                }
            }
        }
        helper(board);
    }
    
private:
    vector<vector<bool>> usedRows;
    vector<vector<bool>> usedCols;
    vector<vector<bool>> usedBlocks;
    bool helper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                
                for (char v = '1'; v <= '9'; ++v) {
                    int index = v - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (!usedRows[i][index] && !usedCols[j][index] && !usedBlocks[k][index]) {
                        board[i][j] = v;
                        usedRows[i][index] = usedCols[j][index] = usedBlocks[k][index] = true;
                        if (helper(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                        usedRows[i][index] = usedCols[j][index] = usedBlocks[k][index] = false;
                    }
                }
                return false;
            }
        }
        
        return true;
    }
};
