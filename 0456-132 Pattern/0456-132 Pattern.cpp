class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
        {
            return false;
        }
        
        stack<int> St;
        int s2 = INT_MIN;
        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] < s2)
            {
                return true;
            }
            
            while (!St.empty() && St.top() < nums[i])
            {
                s2 = St.top();
                St.pop();
            }
            
            St.push(nums[i]);
        }
        
        return false;
    }
};
