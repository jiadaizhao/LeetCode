class Solution {
public:
    int lengthLongestPath(string input) {
        int level = 1, count = 0, maxLen = 0;
        vector<int> lens(1);
        bool isFile = false;
        for (int i = 0; i < input.size(); ++i) {
            while (input[i] == '\t') {
                ++level;
                ++i;
            }
            
            while (i < input.size() && input[i] != '\n') {
                if (input[i] == '.') {
                    isFile = true;
                }
                ++count;
                ++i;
            }
            
            if (isFile) {
                maxLen = max(maxLen, lens[level - 1] + count);
            }
            else {
                if (level >= lens.size()) {
                    lens.push_back(lens.back() + 1 + count);
                }
                else {
                    lens[level] = lens[level - 1] + 1 + count;
                }
            }
            
            level = 1;
            count = 0;
            isFile = false;
        }

        return maxLen;
    }
};
