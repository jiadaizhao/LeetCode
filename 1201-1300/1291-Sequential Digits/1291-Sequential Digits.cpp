class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int i = 1; i < 9; ++i) {
            int num = i, d = i;
            while (num <= high) {
                if (num >= low) {
                    result.push_back(num);
                }
                if (++d > 9) {
                    break;
                }
                num = num * 10 + d;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
