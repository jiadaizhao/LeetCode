class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        --k;
        while (k) {
            int steps = calSteps(n, curr, curr + 1);
            if (steps <= k) {
                ++curr;
                k -= steps;
            }
            else {
                curr *= 10;
                --k;
            }
        }
        
        return curr;
    }
    
private:
    int calSteps(int n, long long n1, long long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min(n + 1LL, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};
