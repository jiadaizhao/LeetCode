class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        if (n == 0) return 0;
        vector<vector<int>> graph(n + 1);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int maxLen = 0;
        dfs(graph, 0, -1, maxLen);
        return maxLen;
    }
    
private:
    int dfs(vector<vector<int>>& graph, int curr, int prev, int& maxLen) {
        int maxLen1 = 0, maxLen2 = 0;
        for (int next : graph[curr]) {
            if (next != prev) {
                int nextLen = dfs(graph, next, curr, maxLen);
                if (nextLen > maxLen1) {
                    maxLen2 = maxLen1;
                    maxLen1 = nextLen;
                }
                else if (nextLen > maxLen2) {
                    maxLen2 = nextLen;
                }
            }
        }
        
        maxLen = max(maxLen, maxLen1 + maxLen2);
        return 1 + maxLen1;
    }
};
