class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        queue<int> Q;
        Q.push(id);
        vector<bool> visited(n);
        visited[id] = true;
        while (!Q.empty() && level--) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int curr = Q.front();
                Q.pop();
                for (int f : friends[curr]) {
                    if (!visited[f]) {
                        Q.push(f);
                        visited[f] = true;
                    }
                }
            }
        }
        
        unordered_map<string, int> table;
        while (!Q.empty()) {
            int f = Q.front();
            Q.pop();
            for (string v : watchedVideos[f]) {
                ++table[v];
            }
        }
        
        vector<pair<int, string>> temp;
        for (auto p : table) {
            temp.push_back({p.second, p.first});
        }
        
        sort(temp.begin(), temp.end());
        vector<string> result;
        for (auto p : temp) {
            result.push_back(p.second);
        }
        return result;
    }
};
