class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int count = 0;
        vector<int> temp(n);
        mergeSort(nums, 0, n - 1, temp, count);

        return count;
    }
    
private:
    void mergeSort(vector<int>& nums, int start, int end, vector<int>& temp, int& count) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(nums, start, mid, temp, count);
            mergeSort(nums, mid + 1, end, temp, count);
            merge(nums, start, mid, end, temp, count);
        }
    }
    
    void merge(vector<int>& nums, int start, int mid, int end, vector<int>& temp, int& count) {
        int i = start, j = mid + 1, p = mid + 1;
        int k = start;
        while (i <= mid) {
            while (p <= end && nums[i] > 2LL * nums[p]) {
                ++p;
            }
            
            count += p - (mid + 1);
            
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
};
