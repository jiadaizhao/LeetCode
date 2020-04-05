class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 3486784401 % n == 0;
    }
};
