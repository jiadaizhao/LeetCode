class Solution {
public:
    int bitwiseComplement(int N) {
        int limit = 2;
        while (N >= limit) {
            limit <<= 1;
        }
        return limit - 1 - N;
    }
};
