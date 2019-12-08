class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (K > 26 || K > S.size()) {
            return 0;
        }
        
        unordered_map<int, int> table;
        int count = 0;
        for (int i = 0; i < K; ++i) {
            ++table[S[i]];
        }
        if (table.size() == K) {
            ++count;
        }
        for (int i = K; i < S.size(); ++i) {
            ++table[S[i]];
            if (--table[S[i - K]] == 0) {
                table.erase(S[i - K]);
            }
            if (table.size() == K) {
                ++count;
            }
        }
        
        return count;
    }
};
