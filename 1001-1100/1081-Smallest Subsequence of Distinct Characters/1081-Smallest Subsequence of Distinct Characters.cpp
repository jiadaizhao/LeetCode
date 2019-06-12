class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> table(26);
        for (char c : text) {
            ++table[c - 'a'];
        }
        vector<bool> used(26);
        string result;
        for (char c : text) {
            --table[c - 'a'];
            if (used[c - 'a']) {
                continue;
            }

            while (result.size() && c < result.back() && table[result.back() - 'a']) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }

            result += c;
            used[c - 'a'] = true;
        }

        return result;
    }
};
