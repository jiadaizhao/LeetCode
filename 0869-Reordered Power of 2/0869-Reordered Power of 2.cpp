class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int result = countDigits(N);
        for (int i = 0; i < 32; ++i) {
            if (result == countDigits(1 << i)) {
                return true;
            }
        }
        return false;
    }
    
private:
    int countDigits(int N) {
       int result = 0;
        while (N) {
            result += pow(10, N % 10);
            N /= 10;
        }
        return result;
    }

};
