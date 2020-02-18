class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                if (!dfs(graph, i, -1, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int curr, int prev, vector<int>& visited) {
        visited[curr] = (prev == -1) ? 1 : 3 - visited[prev];
        for (int next : graph[curr]) {
            if (visited[next] == 0) {
                visited[next] = 3 - visited[curr];
                if (!dfs(graph, next, curr, visited)) {
                    return false;
                }
            }
            else if (visited[next] == visited[curr]) {
                return false;
            }
        }
        
        return true;
    }
};
