class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> table(26);
        int count = 0;
        for (char c : licensePlate) {
            if (c == ' ' || isdigit(c)) {
                continue;
            }
            else {
                ++table[tolower(c) - 'a'];
                ++count;
            }
        }
        
        int minLen = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < words.size(); ++i) {
            int num = count;
            vector<int> need(table.begin(), table.end());
            for (char c : words[i]) {
                if (--need[c - 'a'] >= 0) {
                    --num;
                    if (num == 0) {
                        if (words[i].size() < minLen) {
                            minIndex = i;
                            minLen = words[i].size();
                        }
                        break;
                    }
                }
            }
        }
        
        return words[minIndex];
    }
};
