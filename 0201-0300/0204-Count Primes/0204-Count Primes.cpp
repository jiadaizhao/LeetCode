class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<int> prime(n, true);
        int count = 1;
        int upper = sqrt(n);
        for (int i = 3; i < n; i += 2) {
            if (prime[i]) {
                ++count;
                if (i > upper) {
                    continue;
                }
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        return count;
    }
};
