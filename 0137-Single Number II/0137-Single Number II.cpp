class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        int result = 0;
        for (int i = 0; i < 32; ++i)
        {
            for (int num : nums)
            {
                bits[i] += num >> i & 1;
                bits[i] %= 3;
            }
            result += bits[i] << i;
        }
        
        return result;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // one: bit 1, two: bit 2
        /*
        00 -> 01 -> 10 -> 00
        Truth Table:
        two one num two' one'
        0    0   0   0    0
        0    0   1   0    1
        0    1   0   0    1
        0    1   1   1    0
        1    0   0   1    0
        1    0   1   0    0
        1    1   0   X    X
        1    1   1   X    X
        
        one' = (one ^ num) & (~two)
        two' = (~one') & (two ^ num)
        */
        int one = 0, two = 0;
        for (int num : nums)
        {
            one = (one ^ num) & (~two);
            two = (~one) & (two ^ num);
        }
        return one;
    }
};
