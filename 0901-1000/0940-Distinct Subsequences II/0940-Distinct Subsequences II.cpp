class Solution {
public:
    int distinctSubseqII(string S) {
        long long total = 0;
        int MOD = 1e9 + 7;
        vector<int> end(26);
        for (char c : S) {
            long long temp = total;
            total = (total * 2 + 1 - end[c - 'a'] + MOD) % MOD;
            end[c - 'a'] = (temp + 1) % MOD;
        }
        return total;
    }
};
