class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int maxLen = 0, bal = 0;
        unordered_map<int, int> table;
        for (int i = 0; i < hours.size(); ++i) {
            if (hours[i] > 8) {
                ++bal;
            }
            else {
                --bal;
            }

            if (!table.count(bal)) {
                table[bal] = i;
            }

            if (bal > 0) {
                maxLen = i + 1;
            }
            else if (table.count(bal - 1)) {
                maxLen = max(maxLen, i - table[bal - 1]);
            }
        }

        return maxLen;
    }
};
