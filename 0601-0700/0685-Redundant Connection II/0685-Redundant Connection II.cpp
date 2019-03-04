class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> parent(1 + N);
        vector<int> candA, candB;
        for (auto& edge : edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            }
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
                break;
            }
        }
        
        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
        }
        
        for (auto& edge : edges) {
            if (edge[1] == 0) {
                continue;
            }
            
            int u = edge[0];
            int pu = findParent(parent, u);
            int v = edge[1];
            if (pu == v) {
                if (candA.size()) {
                    return candA;
                }
                else {
                    return edge;
                }
            }
            parent[v] = pu;
        }
        
        return candB;
    }
    
private:
    int findParent(vector<int>& parent, int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        
        return i;
    }
};
