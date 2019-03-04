struct pairhash {
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int minX = INT_MAX;
        int maxX = INT_MIN;
        unordered_set<pair<int, int>, pairhash> table;
        for (auto& p : points) {
            minX = min(minX, p.first);
            maxX = max(maxX, p.first);
            table.insert(p);
        }
        
        int sum = minX + maxX;
        for (auto& p : points) {
            if (table.find({sum - p.first, p.second}) == table.end()) {
                return false;
            }
        }
        
        return true;
    }
};
