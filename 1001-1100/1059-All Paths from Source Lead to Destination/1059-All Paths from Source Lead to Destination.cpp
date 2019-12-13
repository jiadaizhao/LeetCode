class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        vector<int> visited(n);
        return dfs(graph, source, visited, destination);
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int curr, vector<int>& visited, int destination) {
        if (visited[curr] == 1) {
            return true;
        }
        else if (visited[curr] == 2) {
            return false;
        }
        else if (graph[curr].size() == 0) {
            return curr == destination;
        }
        else {
            visited[curr] = 2;
            for (int neighbor : graph[curr]) {
                if (!dfs(graph, neighbor, visited, destination)) {
                    return false;
                }
            }
            visited[curr] = 1;
            return true;
        }
    }
};
