class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++a)
        {
            int b2 = c - a * a;
            int root = sqrt(b2);
            if (root * root == b2)
            {
                return true;
            }
        }
        
        return false;
    }
};
