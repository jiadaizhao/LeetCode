class Solution {
public:
    int minSwaps(vector<int>& data) {
        int target = accumulate(data.begin(), data.end(), 0);
        int count = 0, minS = data.size();
        for (int i = 0; i < data.size(); ++i) {
            if (data[i]) {
                ++count;
            }
            if (i >= target - 1) {
                if (i >= target && data[i - target] == 1) {
                    --count;
                }
                minS = min(minS, target - count);
            }
        }
        return minS;
    }
};
