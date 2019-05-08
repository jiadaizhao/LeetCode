class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<unordered_map<int, int>> graph(N);
        for (auto& edge : edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        
        priority_queue<pair<int, int>> pq;
        pq.emplace(M, 0);
        unordered_map<int, int> visited;
        while (!pq.empty()) {
            int moves = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if (!visited.count(i)) {
                visited[i] = moves;
                for (auto& p : graph[i]) {
                    if (!visited.count(p.first)) {
                        int nextMoves = moves - p.second - 1;
                        if (nextMoves >= 0) {
                            pq.emplace(nextMoves, p.first);
                        }
                    }
                }
            }
        }
        
        int total = visited.size();
        for (auto& edge : edges) {
            total += min(graph[edge[0]][edge[1]], visited[edge[0]] + visited[edge[1]]);
        }
        return total;
    }
};
