class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDist = 0;
        int m = arrays.size();
        int minNum = arrays[0].front();
        int maxNum = arrays[0].back();
        for (int i = 1; i < m; ++i)
        {
            maxDist = max(maxDist, max(abs(arrays[i].back() - minNum), abs(arrays[i].front() - maxNum)));
            minNum = min(minNum, arrays[i].front());
            maxNum = max(maxNum, arrays[i].back());
        }
        
        return maxDist;
    }
};
