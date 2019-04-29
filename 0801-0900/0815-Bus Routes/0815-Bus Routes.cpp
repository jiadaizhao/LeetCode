class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> stationToBus;
        unordered_set<int> visitedBus, visitedStation;
        for (int i = 0; i < n; ++i) {
            for (int station : routes[i]) {
                stationToBus[station].push_back(i);
            }
        }
        
        queue<int> Q;
        Q.push(S);
        visitedStation.insert(S);
        int step = 0;
        while (!Q.empty()) {
            int qs = Q.size();
            ++step;
            for (int i = 0; i < qs; ++i) {
                int s = Q.front();
                Q.pop();
                for (int nb : stationToBus[s]) {
                    if (!visitedBus.count(nb)) {
                        visitedBus.insert(nb);
                        for (int ns : routes[nb]) {
                            if (ns == T) {
                                return step;
                            }
                            if (!visitedStation.count(ns)) {
                                Q.emplace(ns);
                                visitedStation.insert(ns);
                            }                            
                        }
                    }
                }
            }           
        }
        
        return -1;
    }
};
