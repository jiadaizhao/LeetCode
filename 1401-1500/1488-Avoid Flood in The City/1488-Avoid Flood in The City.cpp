class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lake2Day;
        set<int> dry;
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                result[i] = 1;
                dry.insert(i);
            } else {
                if (lake2Day.find(lake) != lake2Day.end()) {
                    auto it = dry.lower_bound(lake2Day[lake]);
                    if (it == dry.end()) {
                        return {};
                    }
                    result[*it] = lake;
                    dry.erase(it);
                }
                lake2Day[lake] = i;
            }
        }
        
        return result;
    }
};
