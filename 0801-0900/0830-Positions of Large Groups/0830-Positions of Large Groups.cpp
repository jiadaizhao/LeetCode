class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int n = S.size(), i = 0;
        while (i < n) {
            int start = i;
            while (i < n && S[i] == S[start]) {
                ++i;
            }
            if (i - start >= 3) {
                result.push_back({start, i - 1});
            }
        }
        return result;
    }
};
