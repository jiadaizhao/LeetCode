class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(1 + num);

        for (int i = 1; i <= num; ++i) {
            result[i] = result[i & (i - 1)] + 1;
        }
        
        return result;
    }
};
