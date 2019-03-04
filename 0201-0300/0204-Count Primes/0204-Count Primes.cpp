class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<int> Prime(n, true);
        int count = 1;
        int upper = sqrt(n);
        for (int i = 3; i < n; i += 2) {
            if (Prime[i]) {
                ++count;
                if (i > upper) {
                    continue;
                }
                for (int j = i * i; j < n; j += i) {
                    Prime[j] = false;
                }
            }
        }
        
        return count;
    }
};
