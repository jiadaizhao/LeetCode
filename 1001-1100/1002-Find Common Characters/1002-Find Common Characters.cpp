class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> table(26);
        for (char c : A[0]) {
            ++table[c - 'a'];
        }
        
        for (int i = 1; i < A.size(); ++i) {
            vector<int> temp(26);
            for (char c : A[i]) {
                ++temp[c - 'a'];
            }
            
            for (int j = 0; j < 26; ++j) {
                if (temp[j] < table[j]) {
                    table[j] = temp[j];
                }
            }
        }
        
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < table[i]; ++j) {
                result.push_back(string(1, 'a' + i));
            }
        }
        
        return result;
    }
};
