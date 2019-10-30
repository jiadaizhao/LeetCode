class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> result(1 << n);
        for (int i = 0; i < (1 << n); ++i) {
            result[i] = start ^ i ^ (i >> 1);
        }

        return result;
    }
};
