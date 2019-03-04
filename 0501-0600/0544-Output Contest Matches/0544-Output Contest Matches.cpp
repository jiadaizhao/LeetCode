class Solution {
public:
    string findContestMatch(int n) {
        int m = n / 2;
        vector<string> result(m);
        for (int i = 0; i < m; ++i) {
            result[i] = '(' + to_string(i + 1) + ',' + to_string(n - i) + ')';
        }
        
        while (m > 1) {
            for (int i = 0; i < m / 2; ++i) {
                result[i] = '(' + result[i] + ',' + result[m - 1 - i] + ')';
            }
            m /= 2;
        }

        return result[0];
    }
};
