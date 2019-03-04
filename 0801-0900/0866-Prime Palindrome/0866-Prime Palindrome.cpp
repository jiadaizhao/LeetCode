class Solution {
public:
    int primePalindrome(int N) {
        if (8 <= N && N <= 11) {
            return 11;
        }
        for (int i = 1; i < 100000; ++i) {
            string left = to_string(i), right(left.rbegin(), left.rend());
            int num = stoi(left + right.substr(1));
            if (num >= N && isPrime(num)) {
                return num;
            }
        }
        return -1;
    }
    
private:
    bool isPrime(int num) {
        if (num < 2 || num % 2 == 0) {
            return num == 2;
        }
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
            
        return true;
    }
};
