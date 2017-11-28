class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int start) {
        if (start == word.size()) {
            return true;
        }
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
            return false;
        }
        
        if (board[i][j] == '#' || board[i][j] != word[start]) {
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '#';
        bool result = dfs(board, i - 1, j, word, start + 1) ||
                      dfs(board, i + 1, j, word, start + 1) ||
                      dfs(board, i, j - 1, word, start + 1) ||
                      dfs(board, i, j + 1, word, start + 1);
                      
        board[i][j] = c;
        return result;
    }
};
