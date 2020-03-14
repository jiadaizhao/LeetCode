class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int result = -1;
        int start = 0, end = n - 1;
        while (true) {
            int index = partition(nums, start, end);
            if (index < n - k) {
                start = index + 1;
            }
            else if (index > n - k) {
                end = index - 1;
            }
            else {
                result = nums[index];
                break;
            }
        }
        
        return result;
    }
    
private:
    int partition(vector<int>& nums, int start, int end) {
        int index = rand() % (end - start + 1);
        swap(nums[end], nums[start + index]);
        int pivot = nums[end];
        int j = start;
        for (int i = start; i < end; ++i) {
            if (nums[i] <= pivot) {
                swap(nums[j++], nums[i]);
            }
        }
        swap(nums[end], nums[j]);
        return j;
    }
};
