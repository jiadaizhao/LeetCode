class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.size(), sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum = (sum + shifts[i]) % 26;
            S[i] = 'a' + (S[i] - 'a' + sum) % 26;
        }
        return S;
    }
};
