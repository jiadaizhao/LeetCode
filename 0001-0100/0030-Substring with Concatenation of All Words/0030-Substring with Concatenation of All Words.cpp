class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int m = s.size();
        int target = words.size();
        if (m == 0 || target == 0) {
            return result;
        }
        int n = words[0].size();
        unordered_map<string, int> table1;
        for (string& word : words) {
            ++table1[word];
        }
        
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> table2;
            int count = 0;
            for (int j = i; j < m - n + 1; j += n) {
                string word = s.substr(j, n);
                if (table1.find(word) == table1.end()) {
                    count = 0;
                    table2.clear();
                }
                else {
                    ++count;
                    ++table2[word];
                    while (table2[word] > table1[word]) {
                        string deleteWord = s.substr(j - (count - 1) * n, n);
                        --table2[deleteWord];
                        --count;
                    }
                    
                    if (count == target) {
                        result.push_back(j - (count - 1) * n);
                        string firstWord = s.substr(j - (count - 1) * n, n);
                        --table2[firstWord];
                        --count;
                    }
                }
            }
        }
        
        return result;
    }
};
