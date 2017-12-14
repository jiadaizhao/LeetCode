class Solution {
public:
    int magicalString(int n) {
        if (n == 0) {
            return 0;
        }
        int count = 1, i = 2;
        string seed = "122";
        while (seed.size() < n) {
            int num = seed[i] - '0';
            if (seed.back() == '1') {
                seed += string(num, '2');
            }
            else {
                seed += string(num, '1');
                count += (seed.size() <= n) ? num : 1;
            }
            ++i;
        }
        
        return count;
    }
};
