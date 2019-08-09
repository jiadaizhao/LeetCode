class Solution {
public:
    int longestDecomposition(string text, int count = 0) {
        int n = text.size();
        for (int i = 1; i <= text.size() / 2; ++i) {
            if (text.substr(0, i) == text.substr(n - i)) {
                return longestDecomposition(text.substr(i, n - i * 2), count + 2);
            }
        }
        return text.size() ? count + 1 : count;
    }
};
