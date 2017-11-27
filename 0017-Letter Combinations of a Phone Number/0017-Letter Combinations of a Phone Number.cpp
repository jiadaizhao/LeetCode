class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }
        dfs(digits, 0, "", result);
        return result;
    }
    
private:
    vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string digits, int start, string path, vector<string>& result) {
        if (start == digits.size()) {
            result.push_back(path);
            return;
        }
        
        int index = digits[start] - '0';
        for (int i = 0; i < table[index].size(); ++i) {
            dfs(digits, start + 1, path + table[index][i], result);
        }
    }    
};
