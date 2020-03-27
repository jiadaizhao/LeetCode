class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(1 + n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<double> probs(1 + n);
        probs[1] = 1;
        dfs(1, 0, t, graph, probs);
        return probs[target];
    }

private:
    void dfs(int curr, int prev, int t, vector<vector<int>>& graph, vector<double>& probs) {
        if (t == 0) {
            return;
        }
        bool stay = true;
        int sz = (curr == 1) ? graph[curr].size() : graph[curr].size() - 1;
        for (int next : graph[curr]) {
            if (next != prev) {
                stay = false;
                probs[next] += probs[curr] / sz;
                dfs(next, curr, t - 1, graph, probs);
            }
        }
        
        if (!stay) {
            probs[curr] = 0;
        }
    }
};
