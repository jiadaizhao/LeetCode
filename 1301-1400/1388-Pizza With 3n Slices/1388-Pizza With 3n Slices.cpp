class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        if (n == 1) {
            return slices[0];
        }
        else if (n == 2) {
            return max(slices[0], slices[1]);
        }
        return max(maxSlice(slices, 0, n - 2), maxSlice(slices, 1, n - 1));
    }
    
private:
    int maxSlice(vector<int>& slices, int start, int end) {
        int n = slices.size() / 3;
        vector<int> dp0(1 + n), dp1(1 + n);
        for (int i = start; i <= end; ++i) {
            vector<int> dp2(1 + n);
            for (int j = 1; j <= n; ++j) {
                dp2[j] = max(dp1[j], dp0[j - 1] + slices[i]);
            }
            dp0 = std::move(dp1);
            dp1 = std::move(dp2);
        }
        return dp1.back();
    }
};
