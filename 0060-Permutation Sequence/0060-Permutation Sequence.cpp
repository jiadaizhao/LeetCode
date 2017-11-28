class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        int fac = 1;
        for (int i = 1; i < n; ++i) {
            fac *= i;
        }
        
        vector<char> nums(n);
        for (int i = 1; i <= n; ++i) {
            nums[i - 1] = '0' + i;
        }
        int base = n - 1;
        --k;
        for (int i = 0; i < n; ++i) {
            int index = k / fac;
            k %= fac;
            result += nums[index];
            nums.erase(nums.begin() + index);
            
            if (base) {
                fac /= base;
                --base;
            }
        }
        
        return result;
    }
};
