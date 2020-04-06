class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), total = 0;
        vector<int> inc1(n), inc2(n), dec1(n), dec2(n);
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++inc1[j];
                    inc2[j] += inc1[i];
                }
                else if (rating[i] > rating[j]) {
                    ++dec1[j];
                    dec2[j] += dec1[i];
                }
            }
            total += inc2[j] + dec2[j];
        }

        return total;
    }
};
