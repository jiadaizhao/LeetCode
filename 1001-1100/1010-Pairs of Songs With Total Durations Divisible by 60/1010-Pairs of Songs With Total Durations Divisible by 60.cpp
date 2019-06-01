class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> table(60);
        int total = 0;
        for (int t : time) {
            t %= 60;
            total += table[(60 - t) % 60];
            ++table[t];
        }
        return total;
    }
};
