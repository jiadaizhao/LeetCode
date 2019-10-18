class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnts, freqs;
        int maxFreq = 0, maxEqual = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            ++cnts[num];
            --freqs[cnts[num] - 1];
            ++freqs[cnts[num]];
            maxFreq = max(maxFreq, cnts[num]);
            if (maxFreq == 1 || maxFreq * freqs[maxFreq] == i ||
                (maxFreq - 1) * freqs[maxFreq - 1] + maxFreq == i + 1) {
                maxEqual = i + 1;
            }
        }

        return maxEqual;
    }
};
