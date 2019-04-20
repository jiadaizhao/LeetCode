class Solution {
public:
    int preimageSizeFZF(int K) {
        long long start = 1, end = ((long long)K + 1) * 5;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long count = trailingZeroes(mid);
            
            if (count > K) {
                end = mid - 1;
            }
            else if (count < K) {
                start = mid + 1;
            }
            else{
                return 5;
            }
        }
        
        return 0;        
    }
    
private:
    long long trailingZeroes(long long n) {
        long long count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        
        return count;
    }
};
