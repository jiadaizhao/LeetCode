class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n < 2) {
            return 0;
        }
        
        vector<int> mask(n);
        int maxp = 0;
        for (int j = 0; j < n; ++j) {
            for (char c : words[j]) {
                mask[j] |= 1 << (c - 'a');
            }
            
            for (int i = 0; i < j; ++i) {
                if ((mask[i] & mask[j]) == 0) {
                    maxp = max(maxp, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return maxp;
    }
};
