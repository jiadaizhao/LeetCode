class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0)
        {
            return b;
        }
        else if (b == 0)
        {
            return a;
        }
        
        while (b)
        {
            int carry = a & b;
            a = a ^ b ;
            b = carry << 1;
        }
        
        return a;
    }
};
