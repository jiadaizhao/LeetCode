class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return k;
        }
        
        int sameColor = k;
        int diffColor = k * (k - 1);
        for (int i = 3; i <= n; ++i)
        {
            int temp = diffColor;
            diffColor = sameColor * (k - 1) + diffColor * (k - 1);
            sameColor = temp;
        }
        
        return sameColor + diffColor;
    }
};
