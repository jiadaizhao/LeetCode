class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x == 0 || (nums.size() & 1) == 0;
    }
};
