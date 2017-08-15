class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0)
        {
            return 0;
        }
        
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                if (j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else if (j == triangle[i].size() - 1)
                {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else
                {
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }
        
        int minSum = INT_MAX;
        for (int j = 0; j < n; ++j)
        {
            
            minSum = min(minSum, triangle[n - 1][j]);
        }
        
        return minSum;
    }
};
