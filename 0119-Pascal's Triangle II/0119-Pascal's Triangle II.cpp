class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        for (int i = 0; i <= rowIndex; ++i)
        {
            vector<int> curr;
            curr.push_back(1);
            if (i != 0)
            {
                for (int j = 0; j < i - 1; ++j)
                {
                    curr.push_back(prev[j] + prev[j + 1]);
                }
                curr.push_back(1);
            }
            
            prev = curr;
        }
        
        return prev;
    }
};
