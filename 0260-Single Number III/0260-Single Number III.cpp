class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2);
        int diff = 0;
        for (int num : nums)
        {
            diff ^= num;
        }
        
        int lastBitMask = (-diff) & diff;
        for (int num : nums)
        {
            if (num & lastBitMask)
            {
                result[0] ^= num;
            }
            else
            {
                result[1] ^= num;
            }
        }
        
        return result;
    }
};
