class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int includeAll = arr[0], maxSum = arr[0], mayDeleteOne = max(arr[0], 0);
        for (int i = 1; i < arr.size(); ++i) {
            mayDeleteOne = max({arr[i], mayDeleteOne + arr[i], includeAll});
            includeAll = max(arr[i], includeAll + arr[i]);
            maxSum = max(maxSum, mayDeleteOne);
            mayDeleteOne = max(mayDeleteOne, 0);
        }
        
        return maxSum;
    }
};
