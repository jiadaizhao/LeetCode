class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> parent(N);
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }
        
        vector<int> result;
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int pa = findParent(parent, a - 1);
            int pb = findParent(parent, b - 1);
            if (pa != pb) {
                parent[pa] = pb;
            }
            else {
                result = edge;
                break;
            }            
        }
        
        return result;
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
