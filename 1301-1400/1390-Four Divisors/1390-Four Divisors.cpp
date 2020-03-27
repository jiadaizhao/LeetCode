class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            int d = 0;
            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    if (d == 0) {
                        d = i;
                    }
                    else {
                        d = 0;
                        break;
                    }
                }
            }
            if (d > 0 && d * d != num) {
                total += 1 + d + num / d + num;
            }
        }
        return total;
    }
};
