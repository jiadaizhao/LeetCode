class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> St1;
        int first = n + 1, last = -1;
        for (int i = 0; i < n; ++i)
        {
            while (!St1.empty() && nums[St1.top()] > nums[i])
            {
                first = min(first, St1.top());
                St1.pop();
            }
            St1.push(i);
        }
        
        if (first == n + 1)
        {
            return 0;
        }
        
        stack<int> St2;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!St2.empty() && nums[St2.top()] < nums[i])
            {
                last = max(last, St2.top());
                St2.pop();
            }
            St2.push(i);
        }

        return last - first + 1;
    }
};

// O(1) space
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        int minNum = INT_MAX, maxNum = INT_MIN;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                flag = true;    
            }
            
            if (flag)
            {
                minNum = min(minNum, nums[i]);
            }
        }

        flag = false;        
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] > nums[i + 1])
            {
                flag = true;    
            }
            
            if (flag)
            {
                maxNum = max(maxNum, nums[i]);
            }
        }

        int l, r;
        for (l = 0; l < n; ++l)
        {
            if (nums[l] > minNum)
            {
                break;
            }
        }
        
        for (r = n - 1; r >= 0; --r)
        {
            if (nums[r] < maxNum)
            {
                break;
            }
        }
        
        return r - l < 0 ? 0 : r - l + 1; 
    }
};
