class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        int n = nums.size();
        vector<int> table(n);
        for (int i = 0; i < n; ++i)
        {
            if (++table[nums[i] - 1] == 2)
            {
                result[0] = nums[i];
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (table[i] == 0)
            {
                result[1] = i + 1;
                break;
            }
        }
        
        return result;
    }
};


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        int n = nums.size();
        for (int i : nums) {
            if (nums[abs(i) - 1] < 0) {
                result[0] = abs(i);
            }
            else {
                nums[abs(i) - 1] *= -1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }
        
        return result;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                result[0] = nums[i];
                result[1] = i + 1;
                break;
            }
        }
        
        return result;
    }
};
