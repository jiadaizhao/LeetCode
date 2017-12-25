class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());        
        int low = 0, high = nums.back() - nums.front();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (count(nums, mid) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
    
private:
    int count(vector<int>& nums, int target) {
        int sum = 0;
        int start = 0, end = 1;
        while (end < nums.size()) {
            if (nums[end] - nums[start] <= target) {                
                sum += end - start;
                ++end;
            }
            else {
                ++start;
                if (start == end) {
                    ++end;
                }
            }            
        }

        return sum;
    }
};
