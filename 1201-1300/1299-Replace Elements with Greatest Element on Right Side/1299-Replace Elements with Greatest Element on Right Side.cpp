class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result(arr.size(), -1);
        int maxRight = arr.back();
        int n = arr.size();
        for (int i = n - 2; i >= 0; --i) {
            result[i] = maxRight;
            maxRight = max(maxRight, arr[i]);
        }
        return result;
    }
};
