class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {        
        if (heaters.size() == 0) {
            return INT_MAX;
        }
        
        int radius = 0;
        sort(heaters.begin(), heaters.end());
        for (int h : houses) {
            auto right = lower_bound(heaters.begin(), heaters.end(), h);
            int rightRadius = (right == heaters.end()) ? h - heaters.back() : *right - h;
            int leftRadius = rightRadius;
            if (right != heaters.begin() && right != heaters.end()) {
                leftRadius = h - *(--right);
            }
            
            radius = max(radius, min(rightRadius, leftRadius));
        }
        
        return radius;
    }
};
