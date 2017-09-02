class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if (n == 0)
        {
            return -1;
        }
        
        vector<int> table(26);
        for (char c : s)
        {
            ++table[c - 'a'];
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (table[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
