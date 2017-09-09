class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int count = 0;
        for (auto& p : points)
        {
            unordered_map<long, int> table;
            for (auto& q : points)
            {
                count += 2 * table[getDistance(p, q)]++;
            }
        }
        
        return count;
    }
    
    long getDistance(pair<int, int>& p1, pair<int, int>& p2)
    {
        return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
    }
};
