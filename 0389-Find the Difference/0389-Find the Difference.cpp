class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> table(26);
        for (char c : s)
        {
            ++table[c - 'a'];
        }
        
        char result = 'a';
        for (char c : t)
        {
            if (--table[c - 'a'] < 0)
            {
                result = c;
                break;
            }
        }
        
        return result;
    }
};
