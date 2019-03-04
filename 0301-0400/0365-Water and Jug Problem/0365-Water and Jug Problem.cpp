class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        
        if (x == 0 && y == 0) {
            return z == 0;
        }
        
        int gcd = GCD(x, y);
        if (z % gcd == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
private:
    int GCD(int x, int y) {
        while (y) {
            int temp = x;
            x = y;
            y = temp % y;
        }
        
        return x;
    }
};
