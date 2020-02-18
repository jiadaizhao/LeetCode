class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0, sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (i >= k) {
                sum -= arr[i - k];
            }
            if (i >= k - 1 && sum / k >= threshold) {
                ++count;
            }
        }
        
        return count;
    }
};
