class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> result(1 + s.size());
        result[0] = 1;
        int candidate = 2;
        int i = 1;
        while (i <= s.size())
        {
            result[i] = i + 1;            
            if (s[i - 1] == 'D')
            {
                int j = i;
                while (i <= s.size() && s[i - 1] == 'D')
                {
                    ++i;
                }
                
                for (int k = j - 1, c = i; k < i; ++k, --c)
                {
                    result[k] = c;
                }
            }
            else
            {
                ++i;
            }
        }

        return result;
    }
};
