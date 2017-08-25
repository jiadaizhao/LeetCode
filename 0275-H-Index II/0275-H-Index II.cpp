class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
        {
            return 0;
        }
        
        int start = 0, end = n - 1;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (citations[n - 1 - mid] >= mid + 1)
            {
                start = mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        if (citations[n - 1 - end] >= end + 1)
        {
            return end + 1;
        }
        else if (citations[n - 1 - start] >= start + 1)
        {
            return start + 1;
        }
        else
        {
            return start;
        }
    }
};
