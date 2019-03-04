class Solution {
public:
    string makeLargestSpecial(string S) {
        int n = S.size();
        int count = 0;
        vector<string> strs;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (S[j] == '1') {
                ++count;
            }
            else {
                --count;
            }
            
            if (count == 0) {
                strs.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        
        sort(strs.begin(), strs.end(), greater<string>());
        string result;
        for (string str : strs) {
            result += str;
        }
        return result;
    }
};
