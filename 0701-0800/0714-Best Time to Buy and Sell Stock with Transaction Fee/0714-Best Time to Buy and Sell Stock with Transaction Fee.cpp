class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n);
        buy[0] = -prices[0];
        vector<int> sell(n);
        for (int i = 1; i < n; ++i) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i] + prices[i] - fee);
        }
        
        return sell[n - 1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < n; ++i) {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, buy + prices[i] - fee);
        }
        
        return sell;
    }
};
