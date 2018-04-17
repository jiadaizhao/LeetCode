class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int count = 0, n = S.size();
        for (string word : words) {
            int i, j = 0;
            for (i = 0; i < n; ++i) {
                if (j < word.size() && S[i] == word[j]) {
                    ++j;
                }
                else if (i > 0 && S[i] == S[i - 1] && i < n - 1 && S[i] == S[i + 1]) {
                    ++i;
                }
                else if (!(i > 1 && S[i] == S[i - 1] && S[i] == S[i - 2])) {
                    break;
                }
            }
            if (i == n && j == word.size()) ++count;
        }
        return count;
    }
};
