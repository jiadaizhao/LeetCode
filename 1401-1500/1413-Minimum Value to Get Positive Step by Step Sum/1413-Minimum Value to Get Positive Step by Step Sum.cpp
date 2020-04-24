class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minSum = 0;
        for (int num : nums) {
            sum += num;
            minSum = min(minSum, sum);
        }
        
        return 1 - minSum;
    }
};
