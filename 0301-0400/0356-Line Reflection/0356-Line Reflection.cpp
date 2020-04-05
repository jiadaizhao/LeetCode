struct pairhash {
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int minX = INT_MAX, maxX = INT_MIN;
        unordered_set<pair<int, int>, pairhash> table;
        for (auto& p : points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            table.insert({p[0], p[1]});
        }
        
        int sum = minX + maxX;
        for (auto& p : points) {
            if (table.find({sum - p[0], p[1]}) == table.end()) {
                return false;
            }
        }
        
        return true;
    }
};
