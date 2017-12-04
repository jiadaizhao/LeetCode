class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> result;
        unordered_map<string, multiset<string>> graph;
        for (auto& t : tickets) {
            graph[t.first].insert(t.second);
        }
        
        stack<string> St;
        St.push("JFK");
        while (!St.empty()) {
            string loc = St.top();
            
            if (graph[loc].size()) {
                auto it = graph[loc].begin();
                St.push(*it);
                graph[loc].erase(it);
            }
            else {
                result.push_back(loc);
                St.pop();
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
