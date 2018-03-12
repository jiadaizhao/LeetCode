class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                visited[i] = 1;
                if (dfs(graph, i, -1, visited) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int curr, int parent, vector<int>& visited) {
        for (int next : graph[curr]) {
            if (visited[next] == 0) {
                visited[next] = 3 - visited[curr];
                if (dfs(graph, next, curr, visited) == false) {
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
