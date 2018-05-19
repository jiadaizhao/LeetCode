class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> graph(N, vector<int>());
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> sums(N), counts(N, 1);
        dfs1(0, -1, graph, sums, counts);
        dfs2(0, -1, graph, sums, counts);
        return sums;
    }
    
private:
    void dfs1(int curr, int prev, vector<vector<int>>& graph, vector<int>& sums, vector<int>& counts) {
        for (int next : graph[curr]) {
            if (next != prev) {
                dfs1(next, curr, graph, sums, counts);
                sums[curr] += sums[next] + counts[next];
                counts[curr] += counts[next];
            }
        }
    }
    
    void dfs2(int curr, int prev, vector<vector<int>>& graph, vector<int>& sums, vector<int>& counts) {
        for (int next : graph[curr]) {
            if (next != prev) {
                sums[next] = sums[curr] - counts[next] + graph.size() - counts[next];                
                dfs2(next, curr, graph, sums, counts);
            }
        }
    }    
};
