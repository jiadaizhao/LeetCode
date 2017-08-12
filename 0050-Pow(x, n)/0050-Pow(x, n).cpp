class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
        {
            return 1;
        }
        
        long long nc = n;
        if (nc < 0)
        {
            nc = -nc;
            x = 1 / x;
        }
        
        double result = 1;
        while (nc)
        {
            if (nc & 1)
            {
                result *= x;
            }
            
            x *= x;
            nc >>= 1;
        }
        
        return result;
    }
};
