class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int count = 0;
        while (z)
        {
            ++count;
            z &= z - 1;
        }
        
        return count;
    }
};
