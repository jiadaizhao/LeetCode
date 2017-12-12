class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minNum = INT_MAX;
        for (int num : nums) {
            sum += num;
            minNum = min(minNum, num);
        }
        
        return sum - minNum * nums.size();
    }
};
