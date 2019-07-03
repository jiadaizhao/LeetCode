class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> loc(1001);
        for (auto trip : trips) {
            loc[trip[1]] += trip[0];
            loc[trip[2]] -= trip[0]; 
        }

        for (int i = 0; i <= 1000; ++i) {
            capacity -= loc[i];
            if (capacity < 0) {
                return false;
            }
        }

        return true;
    }
};
