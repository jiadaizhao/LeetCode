class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int i = 0;
        while (n)
        {
            ++i;
            result = (result << 1) + n % 2;
            n >>= 1;
        }
        return result << (32 - i);
    }
};
