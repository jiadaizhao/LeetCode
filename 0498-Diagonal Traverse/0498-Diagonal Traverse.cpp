class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
        {
            return vector<int>();
        }
        
        int n = matrix[0].size();
        if (n == 0)
        {
            return vector<int>();
        }
        
        vector<int> result(m * n);
        int k = 0;
        int i = 0, j = 0;
        bool up = true;
        while (k < m * n)
        {
            result[k++] = matrix[i][j];
            if (up)
            {
                if (i - 1 >= 0 && j + 1 < n)
                {
                    --i;
                    ++j;
                }
                else if (j + 1 < n)
                {
                    ++j;
                    up = false;
                }
                else
                {
                    ++i;
                    up = false;
                }
            }
            else
            {
                if (i + 1 < m && j - 1 >= 0)
                {
                    ++i;
                    --j;
                }
                else if (i + 1 < m)
                {
                    ++i;
                    up = true;
                }
                else
                {
                    ++j;
                    up = true;
                }
            }
        }
        
        return result;
    }
};
