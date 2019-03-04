class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m) {
            n -= (n & (-n));
        }
        
        return n;
    }
};
