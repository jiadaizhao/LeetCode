class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), maxDist = 0, prev = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (prev != -1) {
                    maxDist = max(maxDist, (i - prev) / 2);
                }
                else {
                    maxDist = i;
                }
                prev = i;
            }
        }
        if (seats.back() == 0) {
            maxDist = max(maxDist, n - 1 - prev);
        }
        return maxDist;        
    }
};
