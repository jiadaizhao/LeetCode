class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> table(26);
        for (string s : B) {
            vector<int> count(26);
            for (char c : s) {
                ++count[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                table[i] = max(table[i], count[i]);
            }
        }
        
        vector<string> result;
        for (string s : A) {
            vector<int> count(26);
            for (char c : s) {
                ++count[c - 'a'];
            }
            bool universal  = true;
            for (int i = 0; i < 26; ++i) {
                if (table[i] > count[i]) {
                    universal  = false;
                    break;
                }
            }
            if (universal ) {
                result.push_back(s);
            }
        }
        return result;
    }
};
