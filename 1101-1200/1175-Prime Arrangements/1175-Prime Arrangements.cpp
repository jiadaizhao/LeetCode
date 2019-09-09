class Solution {
public:
    int numPrimeArrangements(int n) {
        if (n == 1) {
            return 1;
        }
        
        vector<bool> prime(n + 1, true);
        int count = 1;
        for (int i = 3; i <= n; i += 2) {
            if (prime[i]) {
                ++count;
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        int MOD = 1e9 + 7;
        return fac(count, MOD) * fac(n - count, MOD) % MOD;
    }
    
private:
    long fac(int num, int MOD) {
        long result = 1;
        for (int i = 2; i <= num; ++i) {
            result = result * i % MOD;
        }
        return result;
    }
};
