class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (auto& edge : edges) {
            int p1 = findParent(parent, edge.first);
            int p2 = findParent(parent, edge.second);
            if (p1 != p2) {
                parent[p1] = parent[p2];
            }
            else {
                return false;
            }
        }
        
        return true;
    }
    
private:
    int findParent(vector<int>& parent, int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        
        return node;
    }
};
