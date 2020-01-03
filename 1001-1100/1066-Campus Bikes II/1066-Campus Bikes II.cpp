class Node {
public:
    Node(int d, int w, int mk): dist(d), wi(w), mask(mk){}
    int dist;
    int wi;
    int mask;
    bool operator < (const Node& other) const {
        if (dist == other.dist) {
            return wi > other.wi;
        }
        else {
            return dist > other.dist;
        }
    }
};
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue<Node> pq;
        pq.emplace(0, 0, 0);
        unordered_set<int> visited;
        while (!pq.empty()) {
            Node node = pq.top();
            pq.pop();
            int dist = node.dist;
            int wi = node.wi;
            int mask = node.mask;
            if (wi == workers.size()) {
                return dist;
            }
            if (visited.count(mask)) {
                continue;
            }
            visited.insert(mask);
            for (int j = 0; j < bikes.size(); ++j) {
                if (((1 << j) & mask) == 0) {
                    int nmask = (1 << j) | mask;
                    if (!visited.count(nmask)) {
                        int d = abs(workers[wi][0] - bikes[j][0]) + abs(workers[wi][1] - bikes[j][1]);
                        pq.emplace(dist + d, wi + 1, nmask);
                    }
                }
            }
        }
        
        return -1;
    }
};
