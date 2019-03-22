class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> table;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            reverse(word.begin(), word.end());
            table[word] = i;
        }
        
                
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 1; j <= words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (isPalidrome(right) && table.count(left) && table[left] != i) {
                    result.push_back({i, table[left]});
                }
                if (isPalidrome(left) && table.count(right) && table[right] != i) {
                    result.push_back({table[right], i});
                }
            }
        }
        
        if (table.count("")) {
            for (int i = 0; i < words.size(); ++i) {
                if (words[i] != "" && isPalidrome(words[i])) {
                    result.push_back({i, table[""]});
                }
            }
        }
        
        return result;
    }
    
private:
    bool isPalidrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};
