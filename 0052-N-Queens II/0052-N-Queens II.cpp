class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        dfs(0, n, count, flag_col, flag_45, flag_135);
        return count;
    }
    
private:
    void dfs(int row, int n, int& count,
             vector<int>& flag_col, vector<int>& flag_45, vector<int>& flag_135) {
        if (row == n) {
            ++count;
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (flag_col[col] && flag_45[row + col] && flag_135[col - row + n - 1]) {
                flag_col[col] = flag_45[row + col] = flag_135[col - row + n - 1] = 0;
                dfs(row + 1, n, count, flag_col, flag_45, flag_135);
                flag_col[col] = flag_45[row + col] = flag_135[col - row + n - 1] = 1;
            }
        }
    }
};
