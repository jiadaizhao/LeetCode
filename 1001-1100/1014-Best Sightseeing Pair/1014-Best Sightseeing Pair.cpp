class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxScore = -A.size(), maxLocal = A[0];
        for (int i = 1; i < A.size(); ++i) {
            maxScore = max(maxScore, A[i] - i + maxLocal);
            maxLocal = max(maxLocal, A[i] + i);
        }

        return maxScore;
    }
};
