class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curr = 0, total = 0, n = cardPoints.size();
        int sz = n - k, minSum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            curr += cardPoints[i];
            total += cardPoints[i];
            if (i >= sz - 1) {
                if (i >= sz) {
                    curr -= cardPoints[i - sz];
                }
                minSum = min(minSum, curr);
            }
        }
        
        return total - minSum;
    }
};
