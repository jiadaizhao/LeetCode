class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (auto r : richer) {
            graph[r[1]].push_back(r[0]);
        }
        vector<int> result(n);
        iota(result.begin(), result.end(), 0);
        unordered_set<int> visited;
        for (int i = 0; i < n; ++i) {
            if (!visited.count(i)) {
                dfs(graph, i, visited, quiet, result);
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& graph, int curr, unordered_set<int>& visited, vector<int>& quiet, vector<int>& result) {
        visited.insert(curr);
        for (int next : graph[curr]) {
            if (!visited.count(next)) {
                dfs(graph, next, visited, quiet, result);                
            }
            if (quiet[result[next]] < quiet[result[curr]]) {
                result[curr] = result[next];
            }
        }        
    }
};
