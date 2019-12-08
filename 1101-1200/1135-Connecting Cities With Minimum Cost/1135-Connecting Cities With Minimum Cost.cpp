class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<int> parent(1 + N);
        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
        }
        sort(connections.begin(), connections.end(), [](vector<int>& c1, vector<int>& c2){return c1[2] < c2[2];});
        int total = 0, num = 0;
        for (auto c : connections) {
            int p1 = findParent(parent, c[0]);
            int p2 = findParent(parent, c[1]);
            if (p1 != p2) {
                parent[p2] = parent[p1];
                total += c[2];
                if (++num == N - 1) {
                    return total;
                }
            }
        }
        
        return -1;  
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
