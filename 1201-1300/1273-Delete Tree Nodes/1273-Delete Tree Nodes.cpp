class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> graph(nodes);
        for (int i = 1; i < parent.size(); ++i) {
            graph[parent[i]].push_back(i);
        }
        
        return dfs(graph, value, 0).second;
    }
    
private:
    pair<int, int> dfs(vector<vector<int>>& graph, vector<int>& value, int root) {
        int total = value[root], count = 1;
        for (int child : graph[root]) {
            auto p = dfs(graph, value, child);
            total += p.first;
            count += p.second;
        }
        return {total, total != 0 ? count : 0};
    }
};
