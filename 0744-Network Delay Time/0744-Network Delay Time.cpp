class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& time : times) {
            graph[time[0]].emplace_back(time[1], time[2]);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, K);
        unordered_map<int, int> distance;
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (distance.find(node) != distance.end()) {
                continue;
            }
            
            distance[node] = d;
            for (auto& p : graph[node]) {
                int neighbor = p.first;
                int d2 = p.second;
                if (distance.find(neighbor) == distance.end()) {
                    pq.emplace(d + d2, neighbor);
                }
            }
        }
        
        if (distance.size() != N) {
            return -1;
        }
        
        int maxD = 0;
        for (auto d : distance) {
            maxD = max(maxD, d.second);
        }
        
        return maxD;
    }
};
