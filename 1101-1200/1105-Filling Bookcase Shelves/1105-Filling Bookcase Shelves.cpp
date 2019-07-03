class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(1 + books.size());
        for (int j = 1; j < dp.size(); ++j) {
            int width = books[j - 1][0];
            int height = books[j - 1][1];
            dp[j] = dp[j - 1] + height;
            for (int i = j - 1; i > 0; --i) {
                width += books[i - 1][0];
                if (width <= shelf_width) {
                    height = max(height, books[i - 1][1]);
                    dp[j] = min(dp[j], dp[i - 1] + height);
                }
                else {
                    break;
                }
            }
        }

        return dp.back();
    }
};
