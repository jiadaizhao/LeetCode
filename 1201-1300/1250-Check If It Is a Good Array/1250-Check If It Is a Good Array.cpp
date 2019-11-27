class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd = nums[0];
        for (int x : nums) {
            while (x) {
                int temp = gcd;
                gcd = x;
                x = temp % x;
            }
            if (gcd == 1) {
                return true;
            }
        }
        
        return false;
    }
};
