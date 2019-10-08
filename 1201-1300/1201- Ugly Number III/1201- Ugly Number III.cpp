class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int low = 1, high = 2 * (1e9);
        long ab = (long)a * b / __gcd(a, b);
        long bc = (long)b * c / __gcd(b, c);
        long ac = (long)a * c / __gcd(a, c);
        long abc = a * bc / __gcd((long)a, bc);
        while (low < high) {
            int mid = low + (high - low) / 2;
            long count = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
            if (count < n) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low; 
    }
};
