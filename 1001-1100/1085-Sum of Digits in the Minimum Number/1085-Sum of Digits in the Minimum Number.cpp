class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int minA = INT_MAX;
        for (int a : A) {
            minA = min(minA, a);
        }
        int sum = 0;
        while (minA) {
            sum += minA % 10;
            minA /= 10;
        }
        return (sum & 1) ^ 1;
    }
};
