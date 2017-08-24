class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> table(128);
        for (char c : s)
        {
            ++table[c];
        }

        vector<string> result;
        int odd = 0;
        string mid;
        for (int i = 0; i < table.size(); ++i)
        {
            if (table[i] % 2)
            {
                ++odd;
                mid = i;
                if (odd > 1)
                {
                    return result;
                }
            }
        }
        
        for (int i = 0; i < table.size(); ++i)
        {
            table[i] >>= 1;
        }
        
        string path;
        dfs(s.size() / 2, path, table, mid, result);
        return result;
    }

private:
    void dfs(int len, string& path, vector<int>& table, string mid, vector<string>& result)
    {
        if (path.size() == len)
        {
            string rev(path);
            reverse(rev.begin(), rev.end());
            result.push_back(path + mid + rev);
            return;
        }
        
        for (int i = 0; i < table.size(); ++i)
        {
            if (table[i])
            {
                --table[i];
                path.push_back(i);
                dfs(len, path, table, mid, result);
                path.pop_back();
                ++table[i];
            }
        }
    }
};
