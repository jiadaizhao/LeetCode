class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> queens(n, string(n, '.'));
        vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        dfs(0, n, queens, result, flag_col, flag_45, flag_135);
        return result;
    }
    
private:
    void dfs(int row, int n, vector<string>& queens, vector<vector<string>>& result,
             vector<int>& flag_col, vector<int>& flag_45, vector<int>& flag_135)
    {
        if (row == n)
        {
            result.push_back(queens);
            return;
        }
        
        for (int col = 0; col < n; ++col)
        {
            if (flag_col[col] && flag_45[row + col] && flag_135[col - row + n - 1])
            {
                flag_col[col] = flag_45[row + col] = flag_135[col - row + n - 1] = 0;
                queens[row][col] = 'Q';
                dfs(row + 1, n, queens, result, flag_col, flag_45, flag_135);
                queens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[col - row + n - 1] = 1;
            }
        }
    }   
};
