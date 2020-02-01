class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));
        for (auto edge : edges) {
            dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        vector<int> counts(n);
        int minIndex = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++counts[i]; 
                }
            }
            if (counts[i] <= counts[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }
};
