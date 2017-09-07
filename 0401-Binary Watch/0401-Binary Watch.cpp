class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        vector<int> hours = {8, 4, 2, 1};
        vector<int> mins = {32, 16, 8, 4, 2, 1};
        for (int i = 0; i <= num; ++i)
        {
            vector<int> hr = generateDigit(hours, i, true);
            vector<int> mr = generateDigit(mins, num - i, false);
            for (int& h : hr)
            {
                for (int& m : mr)
                {
                    result.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        
        return result;
    }

private:    
    vector<int> generateDigit(vector<int>& nums, int count, bool hour)
    {
        vector<int> res;
        dfs(nums, 0, count, 0, hour, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int start, int count, int val, bool hour, vector<int>& res)
    {
        if (count == 0)
        {
            res.push_back(val);
            return;
        }
        
        int threshold = hour ? 11 : 59;
        for (int i = start; i < nums.size() && nums.size() - i >= count; ++i)
        {
            if (val + nums[i] <= threshold)
            {
                dfs(nums, i + 1, count - 1, val + nums[i], hour, res);
            }
        }
    }
};
