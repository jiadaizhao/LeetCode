class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int n = nums.size();
        if (n == 0) {
            return result;
        }
        
        int start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else if (nums[mid] == target) {
                end = mid; 
            }
            else {
                end = mid - 1;
            }
        }
        
        if (nums[start] == target) {
            result[0] = start;
        }
        else if (nums[end] == target) {
            result[0] = end;
        }
        else {
            return result;
        }
        
        start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else if (nums[mid] == target) {
                start = mid;
            }
            else {
                end = mid - 1;
            }
        }
        
        if (nums[end] == target) {
            result[1] = end;
        }
        else {
            result[1] = start;
        }
        
        return result;
    }
};
