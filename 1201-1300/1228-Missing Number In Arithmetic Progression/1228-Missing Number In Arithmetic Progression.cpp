class Solution {
public:
    int missingNumber(vector<int>& arr) {
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]) {
                return arr[i - 2] + arr[i] - arr[i - 1];
            }
        }
        
        return arr[0];
    }
};
