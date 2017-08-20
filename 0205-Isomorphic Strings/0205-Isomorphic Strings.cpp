class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> table1(256);
        vector<int> table2(256);
        for (int i = 0; i < s.size(); ++i)
        {
            if (table1[s[i]] == 0 && table2[t[i]] == 0)
            {
                table1[s[i]] = t[i];
                table2[t[i]] = s[i];
            }
            else if (table1[s[i]] != t[i])
            {
                return false;
            }
        }
        
        return true;
    }
};
