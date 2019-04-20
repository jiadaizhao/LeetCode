class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) return 0;
        vector<int> dist(n, INT_MAX / 2);
        vector<int> prev(n, INT_MAX / 2);
        dist[src] = 0;
        prev[src] = 0;
        
        for (int k = 0; k <= K; ++k) {
            for (auto& f : flights) {
                dist[f[1]] = min(dist[f[1]], prev[f[0]] + f[2]);
            }
            prev = dist;
        }
                
        return dist[dst] == INT_MAX / 2 ? -1 : dist[dst];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> weights(n, vector<int>(n));
        for (auto f : flights) {
            weights[f[0]][f[1]] = f[2];
        }
        priority_queue<Node> pq;
        unordered_map<int, int> dist;
        pq.emplace(src, 0, 0);
        while (!pq.empty()) {
            Node node = pq.top();
            int city = node.city;
            int cost = node.cost;
            int stop = node.stop;
            pq.pop();
            if (city == dst) return cost;
            if (dist.count(city * n + stop)) continue;
            dist[city * n + stop] = cost;
            if (stop <= K) {
                for (int i = 0; i < n; ++i) {
                    if (weights[city][i] > 0) {
                        pq.emplace(i, cost + weights[city][i], stop + 1);
                    }
                }
            }
        }
        
        return -1;
    }
    
private:
    struct Node {
        int city;
        int cost;
        int stop;
        Node(int ci, int co, int s): city(ci), cost(co), stop(s) {}
        bool operator < (const Node& node) const {
            return cost > node.cost;
        } 
    };
};
