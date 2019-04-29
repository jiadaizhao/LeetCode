class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> result(n);
        int prev = -n;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) {
                prev = i;
            }
            else {
                result[i] = i - prev;
            }         
        }
        
        prev = n * 2;
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) {
                prev = i;
            }
            else {
                result[i] = min(result[i], prev - i);
            }
        }
        
        return result;
    }
};
