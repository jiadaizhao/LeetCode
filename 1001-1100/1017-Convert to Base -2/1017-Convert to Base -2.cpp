class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) {
            return "0";
        }
        string result;
        while (N) {
            result += '0' + (N & 1);
            N = -(N >> 1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
