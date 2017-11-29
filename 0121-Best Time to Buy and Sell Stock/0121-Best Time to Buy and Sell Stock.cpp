class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int maxP = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            maxP = max(maxP, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxP;
    }
};
