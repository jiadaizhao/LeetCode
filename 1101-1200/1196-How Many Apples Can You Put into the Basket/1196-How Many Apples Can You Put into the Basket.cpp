class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        int count = 0, weight = 0;
        sort(arr.begin(), arr.end());
        for (int a : arr) {
            weight += a;
            if (weight > 5000) {
                break;
            }
            else {
                ++count;
            }
        }
        return count;
    }
};
