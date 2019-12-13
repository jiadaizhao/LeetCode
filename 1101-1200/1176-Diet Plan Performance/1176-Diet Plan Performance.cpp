class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int point = 0, sum = 0;
        for (int i = 0; i < calories.size(); ++i) {
            sum += calories[i];
            if (i >= k - 1) {
                if (i >= k) {
                    sum -= calories[i - k];
                }
                
                if (sum < lower) {
                    --point;
                }
                else if (sum > upper) {
                    ++point;
                }
            }
        }
        return point;
    }
};
