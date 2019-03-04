class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        int a = p / g, b = q / g;
        if (a & 1) {
            return (b & 1) ? 1 : 0;
        }
        else {
            return 2;
        }
    }
    
private:
    int gcd(int a, int b) {
        while (b) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }
};
