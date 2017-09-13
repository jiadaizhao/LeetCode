class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        sort(words.begin(), words.end(), [](string& s1, string& s2){return s1.size() < s2.size();});
        for (string& word : words)
        {
            if (isConcatenated(word))
            {
                result.push_back(word);
            }
            else
            {
                dict.insert(word);
            }
        }

        return result;
    }
    
private:
    unordered_set<string> dict;
    bool isConcatenated(string word)
    {
        int n = word.size();
        if (n == 0)
        {
            return false;
        }
        vector<bool> dp(1 + n);
        dp[0] = true;
        for (int j = 1; j <= n; ++j)
        {
            for (int i = j - 1; i >= 0; --i)
            {
                if (dp[i] && dict.find(word.substr(i, j - i)) != dict.end())
                {
                    dp[j] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
