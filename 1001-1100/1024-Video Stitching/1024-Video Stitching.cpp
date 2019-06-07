class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int maxT = 0, count = 0, i = 0;
        while (i < clips.size()) {
            int maxEnd = clips[i][1];
            if (clips[i][0] > maxT) {
                return -1;
            }
            while (i < clips.size() && clips[i][0] <= maxT) {
                maxEnd = max(maxEnd, clips[i++][1]);
            }
            ++count;
            if (maxEnd >= T) {
                return count;
            }
            maxT = maxEnd;
        }
        return -1;
    }
};
