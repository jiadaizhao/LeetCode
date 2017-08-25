class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        return dfs(pattern, 0, str, 0);
    }
    
private:
    unordered_map<string, char> table;
    unordered_set<char> chars;
    bool dfs(string& pattern, int pstart, string& str, int sstart)
    {
        if (pstart == pattern.size())
        {
            if (sstart == str.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        for (int i = sstart; i < str.size() && str.size() - i >= pattern.size() - pstart; ++i)
        {
            string temp = str.substr(sstart, i - sstart + 1);
            if (table.find(temp) != table.end())
            {
                if (table[temp] != pattern[pstart])
                {
                    continue;
                }
                else if (dfs(pattern, pstart + 1, str, i + 1))
                {
                    return true;
                }
            }
            else if (table.find(temp) == table.end() && chars.find(pattern[pstart]) != chars.end())
            {
                continue;
            }
            else
            {
                table[temp] = pattern[pstart];
                chars.insert(pattern[pstart]);
                if (dfs(pattern, pstart + 1, str, i + 1))
                {
                    return true;
                }
                else
                {
                    table.erase(temp);
                    chars.erase(pattern[pstart]);
                }
            }
        }
        
        return false;
    }
};
