class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        
        if (x == 0 && y == 0) {
            return z == 0;
        }
        
        return z % __gcd(x, y) == 0;
    }
};
