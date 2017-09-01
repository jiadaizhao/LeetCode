class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
        {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), cmp());
        vector<int> lis;
        lis.push_back(envelopes[0].second);
        for (int i = 1; i < n; ++i)
        {
            int h = envelopes[i].second; 
            if (h > lis.back())
            {
                lis.push_back(h);
            }
            else
            {
                int index = binarySearch(lis, h);
                lis[index] = h; 
            }
        }
        
        return lis.size();
    }
    
private:
    struct cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2)
        {
            return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
        }
    };
    
    int binarySearch(vector<int>& lis, int target)
    {
        int start = 0, end = lis.size() - 1;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (lis[mid] >= target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if (lis[start] >= target)
        {
            return start;
        }
        else
        {
            return end;
        }
    }
};
