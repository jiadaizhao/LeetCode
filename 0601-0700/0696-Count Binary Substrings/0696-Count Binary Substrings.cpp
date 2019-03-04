class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int i = 0;
        int prev = 0;
        int count = 0;
        while (i < n) {
            int curr = 0;
            char target = s[i];
            while (i < n && s[i] == target) {
                ++curr;
                ++i;
            }
            count += min(prev, curr);
            prev = curr;
        }
        return count;
    }
};

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1;
        int count = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                count += min(prev, curr);
                prev = curr;
                curr = 1;
            }
            else {
                ++curr;
            }
        }
        return count + min(prev, curr);
    }
};
