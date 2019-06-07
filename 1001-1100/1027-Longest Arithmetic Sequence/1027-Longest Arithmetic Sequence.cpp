class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> table;
        int maxLen = 0;
        for (int j = 1; j < A.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                int diff = A[j] - A[i];
                table[j][diff] = table[i].count(diff) ? table[i][diff] + 1 : 2;
                maxLen = max(maxLen, table[j][diff]);
            }
        }
        
        return maxLen;
    }
};
