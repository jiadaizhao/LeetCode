class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;
        vector<int> path = {0};
        dfs(graph, 0, path, result);
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& graph, int start, vector<int>& path, vector<vector<int>>& result) {
        int n = graph.size();
        if (start == n - 1) {
            result.push_back(path);
            return;
        }
        
        for (int i : graph[start]) {
            path.push_back(i);
            dfs(graph, i, path, result);
            path.pop_back();
        }
    }
};
