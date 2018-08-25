class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long long lcm = A * B / __gcd(A, B);
        long long low = 2, high = 1e14;
        int MOD = 1e9 + 7;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (mid / A + mid / B - mid / lcm < N) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low % MOD;
    }
};
