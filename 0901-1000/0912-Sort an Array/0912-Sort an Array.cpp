class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
    
private:
    void mergeSort(vector<int>& nums, int start, int end, vector<int>& temp) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid, temp);
            mergeSort(nums, mid + 1, end, temp);
            int i = start, j = mid + 1, k = start;
            while (i <= mid) {
                while (j <= end && nums[j] < nums[i]) {
                    temp[k++] = nums[j++];
                }
                temp[k++] = nums[i++];
            }
            while (j <= end) {
                temp[k++] = nums[j++];
            }
            for (int i = start; i <= end; ++i) {
                nums[i] = temp[i];
            }
        }
    }
};
