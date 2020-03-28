class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int m = s.size(), target = words.size();
        if (m == 0 || target == 0) {
            return result;
        }
        int n = words[0].size();
        unordered_map<string, int> expected;
        for (string& word : words) {
            ++expected[word];
        }
        
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> seen;
            int count = 0;
            for (int j = i; j < m - n + 1; j += n) {
                string word = s.substr(j, n);
                if (!expected.count(word)) {
                    count = 0;
                    seen.clear();
                }
                else {
                    ++count;
                    ++seen[word];
                    while (seen[word] > expected[word]) {
                        string deleteWord = s.substr(j - (count - 1) * n, n);
                        --seen[deleteWord];
                        --count;
                    }
                    
                    if (count == target) {
                        result.push_back(j - (count - 1) * n);
                        string firstWord = s.substr(j - (count - 1) * n, n);
                        --seen[firstWord];
                        --count;
                    }
                }
            }
        }
        
        return result;
    }
};
