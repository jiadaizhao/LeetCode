class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> path;
            path.push_back(1);
            if (i != 0)
            {
                vector<int>& prev = result[i - 1];
                for (int j = 0; j < i - 1; ++j)
                {
                    path.push_back(prev[j] + prev[j + 1]);
                }
                path.push_back(1);
            }
            
            result.push_back(path);
        }
        
        return result;
    }
};
