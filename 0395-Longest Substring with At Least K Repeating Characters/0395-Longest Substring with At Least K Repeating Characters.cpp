class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k > s.size()) {
            return 0;
        }
        else if (k <= 1) {
            return s.size();
        }
        
        return helper(s, 0, s.size() - 1, k);
    }
    
private:
    int helper(string& s, int start, int end, int k) {
        if (end - start + 1 < k) {
            return 0;
        }
        vector<int> table(26);
        for (int i = start; i <= end; ++i) {
            ++table[s[i] - 'a'];
        }
        
        int left = start, right = end;
        int index = -1;
        while (left <= right) {
            while (left <= right && table[s[left] - 'a'] >= k) {
                ++left;
            }
            
            while (left <= right && table[s[right] - 'a'] >= k) {
                --right;
            }
            
            if (left <= right) {
                index = left;
                ++left;
                --right;
            }
        }
        
        if (index == -1) {
            return end - start + 1;
        }
        else {
            return max(helper(s, start, index - 1, k), helper(s, index + 1, end, k));
        }
    }
};
