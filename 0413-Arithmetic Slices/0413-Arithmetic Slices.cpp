class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3)
        {
            return 0;
        }
        int count = 0;
        int len = 2;
        int diff = A[1] - A[0];
        for (int i = 2; i < n; ++i)
        {
            if (A[i] - A[i - 1] == diff)
            {
                ++len;
            }
            else
            {
                if (len >= 3)
                {
                    count += (len - 1) * (len - 2) / 2;
                }
                len = 2;
                diff = A[i] - A[i - 1];
            }
        }
        
        if (len >= 3)
        {
            count += (len - 1) * (len - 2) / 2;
        }
        
        return count;
    }
};
