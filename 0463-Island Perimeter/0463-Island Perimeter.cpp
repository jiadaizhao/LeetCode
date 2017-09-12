class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
        {
            return 0;
        }
        
        int n = grid[0].size();
        int count = 0;
        int neighbor = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++count;
                    if (i > 0 && grid[i - 1][j])
                    {
                        ++neighbor;
                    }
                    
                    if (j > 0 && grid[i][j - 1])
                    {
                        ++neighbor;
                    }
                }
            }
        }
        
        return count * 4 - neighbor * 2;
    }
};
