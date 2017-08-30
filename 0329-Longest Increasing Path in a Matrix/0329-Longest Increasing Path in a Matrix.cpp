class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n));
        int maxLen = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                maxLen = max(maxLen, dfs(matrix, i, j, cache));
            }
        }
        
        return maxLen;
    }
    
private:
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& cache)
    {
        if (cache[x][y])
        {
            return cache[x][y];
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int maxLen = 1;
        for (int k = 0; k < dx.size(); ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y])
            {
                maxLen = max(maxLen, 1 + dfs(matrix, nx, ny, cache));
            }
        }
        
        return cache[x][y] = maxLen;
    }
};
