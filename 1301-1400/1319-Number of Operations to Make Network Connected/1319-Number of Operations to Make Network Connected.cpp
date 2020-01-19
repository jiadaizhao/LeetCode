class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        int count = n - 1;
        vector<int> parent(n);
        for (int i = 1; i < n; ++i) {
            parent[i] = i;
        }
        for (auto c : connections) {
            int pa = findParent(parent, c[0]);
            int pb = findParent(parent, c[1]);
            if (pa != pb) {
                --count;
                parent[pb] = pa;
            }
        }
        
        return count;
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
