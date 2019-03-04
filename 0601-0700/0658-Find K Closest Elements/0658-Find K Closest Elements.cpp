class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        
        int left = index - 1;
        int right = index;
        while (k--) {
            if (left >= 0 && (right == n || x - arr[left] <= arr[right] - x)) {
                --left;
            }
            else {
                ++right;
            }
        }
        
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);        
    }
};
