class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size();
        if (m == 0)
        {
            return 0;
        }
        
        int n = picture[0].size();
        int count = 0;
        vector<int> rowB(m);
        vector<int> colB(n);
        unordered_map<int, vector<int>> colTable;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (picture[i][j] == 'B')
                {
                    ++rowB[i];
                    ++colB[j];
                    colTable[j].push_back(i);
                }
            }
        }
        
        for (int j = 0; j < n; ++j)
        {
            if (colB[j] != N)
            {
                continue;
            }
            int i = colTable[j][0];
            if (rowB[i] == N)
            {
                bool same = true;
                for (int k = 1; k < colTable[j].size(); ++k)
                {
                    int row = colTable[j][k];
                    for (int col = 0; col < n; ++col)
                    {
                        if (picture[row][col] != picture[i][col])
                        {
                            same = false;
                            break;
                        }
                    }
                    
                    if (same == false)
                    {
                        break;
                    }
                }
                
                if (same)
                {
                    count += colTable[j].size();
                }
            }
        }
        
        return count;
    }
};
