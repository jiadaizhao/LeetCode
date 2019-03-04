class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.size(), sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum = (sum + shifts[i]) % 26;
            int c = S[i] + sum;
            if (c > 'z') {
                S[i] = c - 'z' - 1 + 'a';
            }
            else {
                S[i] = c;
            }
        }
        return S;
    }
};
