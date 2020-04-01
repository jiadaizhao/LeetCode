class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        
        for (int p : vector<int>{2, 3, 5}) {
            while (num % p == 0) {
                num /= p;
            } 
        }
        
        return num == 1;
    }
};
