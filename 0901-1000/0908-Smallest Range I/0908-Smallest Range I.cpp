class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxNum = INT_MIN, minNum = INT_MAX;
        for (int a : A) {
            maxNum = max(maxNum, a);
            minNum = min(minNum, a);
        }
        return max(0, maxNum - minNum - K * 2);
    }
};
