class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), cmp());
        vector<int> lis = {envelopes[0].second};
        for (int i = 1; i < n; ++i) {
            int h = envelopes[i].second; 
            if (h > lis.back()) {
                lis.push_back(h);
            }
            else {
                auto it = lower_bound(lis.begin(), lis.end(), h);
                *it = h; 
            }
        }
        
        return lis.size();
    }
    
private:
    struct cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
        }
    };
};
