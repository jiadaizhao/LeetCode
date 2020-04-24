class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> table(128);
        for (char c : s) {
            ++table[c];
        }
        
        int sum = 0, odd = 0;
        for (int i : table) {
            if (i & 1) {
                odd = 1;
                sum += i - 1;
            }
            else {
                sum += i;
            }
        }
        
        return sum + odd;
    }
};
