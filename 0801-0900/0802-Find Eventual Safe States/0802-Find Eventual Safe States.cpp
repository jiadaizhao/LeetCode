class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> edges(n);
        vector<int> degrees(n);
        queue<int> Q;
        for (int i = 0; i < n; ++i) {
            degrees[i] = graph[i].size();
            if (degrees[i] == 0) {
                Q.push(i);
            }
            else {
                for (int j : graph[i]) {
                    edges[j].push_back(i);
                }
            }           
        }
      
        vector<bool> safe(n);
        while (!Q.empty()) {
            int u = Q.front();
            safe[u] = true;
            Q.pop();
            for (int v : edges[u]) {
                if (--degrees[v] == 0) {
                    Q.push(v);
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
