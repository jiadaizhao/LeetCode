class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = arr[1] - arr[0];
        vector<vector<int>> result = {{arr[0], arr[1]}};
        for (int i = 2; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {{arr[i - 1], arr[i]}};
            }
            else if (diff == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};
