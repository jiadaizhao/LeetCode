class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        dfs(word, 0, "", false, result);
        return result;
    }
    
private:
    void dfs(string& word, int start, string path, bool prenum, vector<string>& result)
    {
        if (start == word.size())
        {
            result.push_back(path);
            return;
        }
        
        dfs(word, start + 1, path + word[start], false, result);
        if (!prenum)
        {
            for (int i = start; i < word.size(); ++i)
            {
                dfs(word, i + 1, path + to_string(i - start + 1), true, result);
            }
        }
    }
};
