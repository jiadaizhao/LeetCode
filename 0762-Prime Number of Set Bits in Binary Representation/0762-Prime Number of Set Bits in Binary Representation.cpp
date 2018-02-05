class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int i = L; i <= R; ++i) {
            int num = i;
            int sum = 0;
            while (num) {
                ++sum;
                num &= (num - 1);
            }
            if (find(primes.begin(), primes.end(), sum) != primes.end()) ++count;
        }
        return count;
    }
};
