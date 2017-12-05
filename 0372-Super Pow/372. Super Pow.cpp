class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int p = 0;
        for (int i : b) {
            p = (p * 10 + i) % 1140;
        }
        if (p == 0) {
            p = 1140;
        }
        return power(a, p, 1337);
    }
    
    int power(int x, int n, int mod) {
        int ret = 1;
        x %= mod;
        while (n) {
            if (n & 1) {
                ret = ret * x % mod;
            }
            x = x * x % mod;
            n /= 2;
        }
        
        return ret;
    }
};
