class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> usedRows(9, vector<bool>(9, false));
        vector<vector<bool>> usedCols(9, vector<bool>(9, false));
        vector<vector<bool>> usedBlocks(9, vector<bool>(9, false));
        
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int index = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (usedRows[i][index] || usedCols[index][j] || usedBlocks[k][index])
                    {
                        return false;
                    }
                    usedRows[i][index] = usedCols[index][j] = usedBlocks[k][index] = true;
                }
            }
        }
        
        return true;
    }
};
