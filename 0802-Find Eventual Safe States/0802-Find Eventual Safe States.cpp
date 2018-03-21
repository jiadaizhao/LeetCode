class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> edges(n);
        vector<int> degrees(n);
        for (int i = 0; i < n; ++i) {
            degrees[i] = graph[i].size();
            for (int j : graph[i]) {
                edges[j].push_back(i);
            }
        }
        
        queue<int> Q;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 0) {
                Q.push(i);
            }
        }
        
        vector<int> result;
        while (!Q.empty()) {
            int u = Q.front();
            result.push_back(u);
            Q.pop();
            for (int v : edges[u]) {
                if (--degrees[v] == 0) {
                    Q.push(v);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
