class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> table(26);
        int sum = p.size();
        for (char c : p)
        {
            ++table[c - 'a'];
        }
        
        vector<int> result;
        int n = s.size();
        int count = 0;
        int j = 0;
        for (int i = 0; i < n - sum + 1; ++i)
        {
            while (j < i + sum)
            {
                if (table[s[j] - 'a']-- > 0)
                {
                    ++count;
                }
                ++j;
            }
            
            if (count == sum)
            {
                result.push_back(i);
            }
            
            if (++table[s[i] - 'a'] > 0)
            {
                --count;
            }
        }
        
        return result;
    }
};
