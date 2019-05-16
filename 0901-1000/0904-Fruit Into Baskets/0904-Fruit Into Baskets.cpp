class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int maxCount = 0, count = 0, count2 = 0;
        int prev1 = 0, prev2 = 0;
        for (int t : tree) {
            if (t == prev1 || t == prev2) {
                count += 1;
            }
            else {
                count = count2 + 1;
            }
            
            maxCount = max(maxCount, count);
            if (t == prev2) {
                count2 += 1;
            }
            else {
                count2 = 1;
                prev1 = prev2;
                prev2 = t;
            }
        }
        return maxCount;
    }
};
