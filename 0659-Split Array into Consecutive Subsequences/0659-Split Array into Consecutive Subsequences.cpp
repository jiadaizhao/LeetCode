class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, append;
        for (int& num : nums)
        {
            ++freq[num];
        }
        
        for (int& num : nums)
        {
            if (freq[num] == 0)
            {
                continue;
            }
            else if (append[num] > 0)
            {
                --append[num];
                ++append[num + 1];
            }
            else if (freq[num + 1] > 0 && freq[num + 2] > 0)
            {
                --freq[num + 1];
                --freq[num + 2];
                ++append[num + 3];
            }
            else
            {
                return false;
            }
            --freq[num];
        }
        
        return true;
    }
};
