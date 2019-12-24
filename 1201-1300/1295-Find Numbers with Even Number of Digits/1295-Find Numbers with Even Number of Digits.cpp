class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int len = 0;
            while (num) {
                ++len;
                num /= 10;
            }
            if ((len & 1) == 0) {
                ++count;
            }
        }
        return count;
    }
};
