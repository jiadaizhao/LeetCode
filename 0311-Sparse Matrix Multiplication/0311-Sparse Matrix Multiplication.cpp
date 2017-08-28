class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), p = B[0].size();
        vector<vector<int>> result(m, vector<int>(p));
        for (int i = 0; i < m; ++i)
        {
            for (int k = 0; k < n; ++k)
            {
                if (A[i][k])
                {
                    for (int j = 0; j < p; ++j)
                    {
                        result[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        
        return result;
    }
};
