class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            result[i] = match(queries[i], pattern);
        }
        return result;
    }
    
private:
    bool match(string& query, string& pattern) {
        int j = 0;
        for (char c : query) {
            if (j < pattern.size() && c == pattern[j]) {
                ++j;
            }
            else if (!islower(c)) {
                return false;
            }
        }
        
        return j == pattern.size();
    }
};
