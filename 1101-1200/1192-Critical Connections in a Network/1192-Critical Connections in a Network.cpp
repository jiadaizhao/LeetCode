class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for (auto c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        rank = vector<int>(n, -1);
        vector<vector<int>> result;
        dfs(0, -1, 0, result);
        return result;
    }
    
private:
    unordered_map<int, vector<int>> graph;
    vector<int> rank;
    int dfs(int curr, int prev, int depth, vector<vector<int>>& result) {
        if (rank[curr] >= 0) {
            return rank[curr];
        }
        
        rank[curr] = depth;
        for (int neighbor : graph[curr]) {
            if (neighbor == prev) {
                continue;
            }
            int nextDepth = dfs(neighbor, curr, depth + 1, result);
            if (nextDepth > depth) {
                result.push_back({curr, neighbor});
            }
            rank[curr] = min(rank[curr], nextDepth);
        }
        
        return rank[curr];
    }
};

// Tarjan
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for (auto c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        low = vector<int>(n, -1);
        id = vector<int>(n, -1);
        vector<vector<int>> result;
        dfs(0, -1, result);
        return result;
    }
    
private:
    unordered_map<int, vector<int>> graph;
    vector<int> low, id;
    void dfs(int curr, int prev, vector<vector<int>>& result) {
        static int time = 0;
        low[curr] = id[curr] = ++time;
        for (int neighbor : graph[curr]) {
            if (neighbor == prev) {
                continue;
            }
            if (low[neighbor] == -1) {
                dfs(neighbor, curr, result);
                low[curr] = min(low[curr], low[neighbor]);
                if (id[curr] < low[neighbor]) {
                    result.push_back({curr, neighbor});
                }
            }
            else {
                low[curr] = min(low[curr], id[neighbor]);
            }
        }
    }
};
