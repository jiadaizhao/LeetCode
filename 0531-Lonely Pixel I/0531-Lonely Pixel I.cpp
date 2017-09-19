class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        if (m == 0)
        {
            return 0;
        }
        
        int n = picture[0].size();
        int count = 0;
        vector<int> rowB(m);
        vector<int> colB(n);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (picture[i][j] == 'B')
                {
                    ++rowB[i];
                    ++colB[j];
                }
            }
        }
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (picture[i][j] == 'B' && rowB[i] == 1 && colB[j] == 1)
                {
                    ++count;
                }
            }
        }
        
        return count;
    }
};
