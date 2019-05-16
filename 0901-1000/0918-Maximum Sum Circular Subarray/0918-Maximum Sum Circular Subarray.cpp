class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum = INT_MIN, sum = 0, currMax = 0, minSum = 0, currMin = 0;
        for (int a : A) {
            if (currMax < 0) {
                currMax = 0;
            }
            currMax += a;
            if (currMin > 0) {
                currMin = 0;
            } 
            currMin += a;
            sum += a;
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        
        if (minSum != sum) {
            maxSum = max(maxSum, sum - minSum);
        }        
        return maxSum;
    }
};
