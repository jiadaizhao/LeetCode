class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> result(positions.size());
        vector<int> parent(m * n, -1);
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        int count = 0;
        for (int i = 0; i < positions.size(); ++i) {
            int r = positions[i].first;
            int c = positions[i].second;
            if (parent[r * n + c] == -1) {
                parent[r * n + c] = r * n + c;
                ++count;
                for (int k = 0; k < dr.size(); ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && parent[nr * n + nc] != -1) {
                        int p1 = findParent(parent, r * n + c);
                        int p2 = findParent(parent, nr * n + nc);
                        if (p1 != p2) {
                            --count;
                            parent[p2] = p1;
                        }
                    }
                }
            }
            result[i] = count;
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
