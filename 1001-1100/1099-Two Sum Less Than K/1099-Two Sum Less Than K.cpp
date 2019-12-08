class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int maxS = -1, start = 0, end = A.size() - 1;
        while (start < end) {
            int curr = A[start] + A[end];
            if (curr >= K) {
                --end;
            }
            else {
                maxS = max(maxS, curr);
                start += 1;
            }
        }
        
        return maxS;
    }
};
