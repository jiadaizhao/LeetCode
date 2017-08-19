class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
        {
            return 0;
        }
        
        int n = grid[0].size();
        queue<pair<int, int>> Q;
        int count = 0;
        vector<int> deltaX = {-1, 1, 0, 0};
        vector<int> deltaY = {0, 0, -1, 1};
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++count;
                    grid[i][j] = '0';
                    Q.push({i, j});
                    while (!Q.empty())
                    {
                        int r = Q.front().first;
                        int c = Q.front().second;
                        Q.pop();
                        for (int k = 0; k < deltaX.size(); ++k)
                        {
                            int row = r + deltaX[k];
                            int col = c + deltaY[k];
                            if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1')
                            {
                                grid[row][col] = '0';
                                Q.push({row, col});
                            }
                        }
                        
                    }
                }
            }
        }
        
        return count;
    }
};
