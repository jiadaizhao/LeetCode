class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> ugly(n, 1);
        for (int i = 1; i < n; ++i) {
            ugly[i] = min({ugly[p2] * 2, ugly[p3] * 3, ugly[p5] * 5});
            if (ugly[p2] * 2 == ugly[i]) {
                ++p2;
            }
            
            if (ugly[p3] * 3 == ugly[i]) {
                ++p3;
            }
            
            if (ugly[p5] * 5 == ugly[i]) {
                ++p5;
            }
        }
        
        return ugly[n - 1];        
    }
};
