class Solution {
public:
    int uniqueLetterString(string S) {
        int n = S.size();
        vector<int> last(26, -1);
        vector<int> prev(n, -1), next(n, -1);
        for (int i = 0; i < n; ++i) {
            int index = S[i] - 'A';
            prev[i] = last[index];
            last[index] = i;            
        }
        
        fill(last.begin(), last.end(), -1);
        for (int i = n - 1; i >= 0; --i) {
            int index = S[i] - 'A';
            next[i] = last[index];
            last[index] = i;    
        }

        int count = 0, MOD = 1000000007;
        for (int i = 0; i < n; ++i) {
            int l1 = i - prev[i];
            int l2 = (next[i] == -1) ? n - i : next[i] - i;
            count = (count + l1 * l2) % MOD;
        }
        return count;
    }
};
