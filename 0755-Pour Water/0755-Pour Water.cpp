class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n = heights.size();
        while (V--) {
            int left = K - 1;
            int candidate = -1;
            while (left >= 0 && heights[left] <= heights[left + 1]) {
                if (heights[left] < heights[left + 1]) {
                    candidate = left;
                }
                --left;
            }
            if (candidate != -1) {
                ++heights[candidate];
                continue;
            }
            
            int right = K + 1;
            candidate = -1;
            while (right < n && heights[right] <= heights[right - 1]) {
                if (heights[right] < heights[right - 1]) {
                    candidate = right;
                }
                ++right;
            }
            if (candidate != -1) {
                ++heights[candidate];
                continue;
            }
            ++heights[K];
        }
        
        return heights;
    }
};
