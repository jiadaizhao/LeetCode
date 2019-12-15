class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<int> parent(1 + n);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
        
        vector<vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            edges.push_back({wells[i], 0, i + 1});
        }
        for (auto& p : pipes) {
            edges.push_back({p[2], p[0], p[1]});
        }        
        
        sort(edges.begin(), edges.end());
        int cost = 0;
        for (auto& edge : edges) {
            int p1 = findParent(parent, edge[1]);
            int p2 = findParent(parent, edge[2]);
            if (p1 != p2) {
                cost += edge[0];
                parent[p2] = p1;
                if (--n == 0) {
                    break;
                }
            }
        }
        
        return cost;
    }
    
private:
    int findParent(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};
