class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        bool diff = true;
        while (diff) {
            vector<int> curr(arr.begin(), arr.end());
            diff = false;
            for (int i = 1; i < arr.size() - 1; ++i) {
                if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                    ++curr[i];
                    diff = true;
                }
                else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    --curr[i];
                    diff = true;
                }
            }
            arr = curr;
        }
        
        return arr;
    }
};
