class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int m = x.size();
        if (m <= 3)
        {
            return false;
        }
        
        for (int i = 3; i < m; ++i)
        {
            // Line 4 crosses line 1.
            if (x[i] >= x[i - 2] && x[i - 3] >= x[i - 1])
            {
                return true;
            }
            
            // Line 5 crosses line 1.
            if (i > 3)
            {
                if (x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
                {
                    return true;
                }
            }
            
            // Line 6 crosses line 1.
            if (i > 4)
            {
                if (x[i - 2] >= x[i - 4] && x[i] + x[i - 4] >= x[i - 2] && x[i - 3] >= x[i - 1] && x[i - 5] + x[i - 1] >= x[i - 3])
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
