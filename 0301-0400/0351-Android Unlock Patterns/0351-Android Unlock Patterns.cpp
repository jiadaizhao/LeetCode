class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
        
        int count = 0;
        vector<bool> visited(10);
        for (int i = m; i <= n; ++i) {
            count += dfs(skip, visited, 1, i - 1) * 4;
            count += dfs(skip, visited, 2, i - 1) * 4;
            count += dfs(skip, visited, 5, i - 1);
        }
        
        return count;
    }
    
private:
    int dfs (vector<vector<int>>& skip, vector<bool>& visited, int curr, int remain) {
        if (remain == 0) {
            return 1;
        }
        
        --remain;
        int count = 0;
        visited[curr] = true;
        for (int i = 1; i <= 9; ++i) {
            if (!visited[i] && (skip[curr][i] == 0 || visited[skip[curr][i]])) {
                count += dfs(skip, visited, i, remain);
            }
        }
        visited[curr] = false;
        return count;
    }
};
