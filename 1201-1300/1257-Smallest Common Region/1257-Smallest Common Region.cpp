class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        for (auto& region : regions) {
            for (int i = 1; i < region.size(); ++i) {
                parent[region[i]] = region[0];
            }
        }
        
        unordered_set<string> path;
        path.insert(region1);
        while (parent.count(region1)) {
            region1 = parent[region1];
            path.insert(region1);
        }
        
        while (!path.count(region2)) {
            region2 = parent[region2];
        }
        
        return region2;
    }
};
