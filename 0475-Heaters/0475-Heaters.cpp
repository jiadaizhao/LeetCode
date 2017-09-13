class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.size() == 0)
        {
            return 0;
        }
        
        if (heaters.size() == 0)
        {
            return INT_MAX;
        }
        
        int radius = INT_MIN;
        sort(heaters.begin(), heaters.end());
        for (int h : houses)
        {
            int right = firstLargerOrEqual(heaters, h);
            int rightRadius = (right == -1) ? h - heaters.back() : heaters[right] - h;
            int left = -1;
            if (right == -1)
            {
                left = heaters.size() - 1;
            }
            else if (right > 0)
            {
                left = right - 1;
            }
            int leftRadius = (left == -1) ? heaters.front() - h : h - heaters[left];
            
            radius = max(radius, min(rightRadius, leftRadius));
        }
        
        return radius;
    }
    
private:
    int firstLargerOrEqual(vector<int>& heaters, int h)
    {
        int n = heaters.size();
        int start = 0, end = n - 1;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (heaters[mid] >= h)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        if (heaters[start] >= h)
        {
            return start;
        }
        else if (heaters[end] >= h)
        {
            return end;
        }
        else
        {
            return -1;
        }
    }
};
