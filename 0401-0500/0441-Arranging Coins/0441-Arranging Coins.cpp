class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1 + 8LL * n) - 1) / 2;
    }
};
