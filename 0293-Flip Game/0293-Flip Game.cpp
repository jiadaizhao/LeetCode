class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        int n = s.size();
        if (n == 0) {
            return result;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                result.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        
        return result;
    }
};
