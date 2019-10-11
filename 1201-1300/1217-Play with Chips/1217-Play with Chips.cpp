class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even = 0, odd = 0;
        for (int i : chips) {
            if (i & 1) {
                ++odd;
            }
            else {
                ++even;
            }
        }

        return min(even, odd);
    }
};
