class Solution {
public:
    string generateTheString(int n) {
        return 'a' + string(n - 1, 'b' - (n & 1));
    }
};
