class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> table;
        int maxLen = 0;
        for (int a : arr) {
            table[a] = table[a - difference] + 1;
            maxLen = max(maxLen, table[a]); 
        }

        return maxLen;
    }
};
