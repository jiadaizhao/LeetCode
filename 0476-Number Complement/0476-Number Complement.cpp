class Solution {
public:
    int findComplement(int num) {
        unsigned int limit = 1;
        while (num >= limit) {
            limit <<= 1;
        }
        return limit - 1 - num;
    }
};
