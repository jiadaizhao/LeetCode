class Solution {
public:
    int maxScore(string s) {
        int count0 = 0, count1 = 0;
        int maxDiff = INT_MIN, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++count0;
            }
            else {
                ++count1;
            }
            if (i != n - 1) {
                maxDiff = max(maxDiff, count0 - count1);
            }            
        }
        return maxDiff + count1;
    }
};
