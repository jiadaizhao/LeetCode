class Solution {
public:
    string smallestGoodBase(string n) {
        string result;
        long num = stol(n);
        int maxm = log2(num);
        for (int m = maxm; m > 1; --m) {
            long k = pow(num, 1.0 / m);
            long temp = num;
            bool found = true;
            while (temp) {
                if (temp % k != 1) {
                    found = false;
                    break;
                }
                
                temp = (temp - 1) / k;
            }
            
            if (found) {
                return to_string(k);
            }
        }
        
        return to_string(num - 1);
    }
};
