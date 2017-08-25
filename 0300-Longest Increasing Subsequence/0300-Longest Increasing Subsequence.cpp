class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        
        vector<int> seq = {nums[0]};
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > seq.back())
            {
                seq.push_back(nums[i]);
            }
            else
            {
                int index = binarySearch(seq, nums[i]);
                seq[index] = nums[i];
            }
        }
        
        return seq.size();
    }
    
private:
    // Find lower bound of target, namely >= target
    int binarySearch(vector<int>& seq, int target)
    {
        int start = 0, end = seq.size() - 1;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (seq[mid] >= target)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        if (seq[start] >= target)
        {
            return start;
        }
        else
        {
            return end;
        }
    }
};
