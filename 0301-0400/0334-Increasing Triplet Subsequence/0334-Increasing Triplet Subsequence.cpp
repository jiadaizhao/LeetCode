class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, big = INT_MAX;
        for (int num : nums) {
            if (num <= small) {
                small = num;
            }
            else if (num <= big) {
                big = num;
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};
