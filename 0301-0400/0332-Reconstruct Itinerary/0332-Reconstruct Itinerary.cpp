class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        sort(tickets.begin(), tickets.end(), greater<vector<string>>());
        unordered_map<string, vector<string>> graph;
        for (auto& t : tickets) {
            graph[t[0]].push_back(t[1]);
        }
        
        stack<string> St;
        St.push("JFK");
        while (!St.empty()) {
            string curr = St.top();            
            if (graph[curr].size()) {
                St.push(graph[curr].back());
                graph[curr].pop_back();
            }
            else {
                result.push_back(curr);
                St.pop();
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
