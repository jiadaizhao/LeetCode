class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (auto r : richer) {
            graph[r[1]].push_back(r[0]);
        }
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            if (result[i] == -1) {
                dfs(graph, i, quiet, result);
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& graph, int curr, vector<int>& quiet, vector<int>& result) {
        result[curr] = curr;
        for (int next : graph[curr]) {
            if (result[next] == -1) {
                dfs(graph, next, quiet, result);                
            }
            if (quiet[result[next]] < quiet[result[curr]]) {
                result[curr] = result[next];
            }
        }        
    }
};
