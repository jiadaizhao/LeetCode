class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int i = 0, j = 0, count = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] > arr2[j] + d) {
                ++j;
            }
            else {
                if (arr1[i] < arr2[j] - d) {
                    ++count;
                }
                ++i;
            }
        }
        count += arr1.size() - i;
        return count;
    }
};
