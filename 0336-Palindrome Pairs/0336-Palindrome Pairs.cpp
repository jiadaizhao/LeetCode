class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> table;
        for (int i = 0; i < words.size(); ++i)
        {
            string word = words[i];
            reverse(word.begin(), word.end());
            table[word] = i;
        }
        
        if (table.find("") != table.end())
        {
            int j = table[""];
            for (int i = 0; i < words.size(); ++i)
            {
                if (i != j && isPalindrome(words[i]))
                {
                    result.push_back({j, i});
                }
            }
        }
        
        for (int i = 0; i < words.size(); ++i)
        {
            string word = words[i];
            for (int j = 0; j < word.size(); ++j)
            {
                string left = word.substr(0, j);
                string right = word.substr(j);
                
                if (table.find(left) != table.end() && table[left] != i && isPalindrome(right))
                {
                    result.push_back({i, table[left]});
                }
                
                if (table.find(right) != table.end() && table[right] != i && isPalindrome(left))
                {
                    result.push_back({table[right], i});
                }
            }
        }
        
        return result;
    }
    
private:
    bool isPalindrome(string s)
    {
        if (s.size() == 0)
        {
            return true;
        }
        
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            ++start;
            --end;
        }
        
        return true;
    }
};
