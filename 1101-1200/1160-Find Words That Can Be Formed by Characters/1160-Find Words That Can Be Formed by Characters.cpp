class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> table(26);
        for (char c : chars) {
            ++table[c - 'a'];
        }

        int total = 0;
        for (string word : words) {
            vector<int> temp(table.begin(), table.end());
            bool good = true;
            for (char c : word) {
                if (--temp[c - 'a'] < 0) {
                    good = false;
                    break;
                }
            }

            if (good) {
                total += word.size();
            }
        }

        return total;
    }
};
