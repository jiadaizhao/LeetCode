class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> table(n);
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) {
                table[manager[i]].push_back(i);
            }            
        }
        queue<pair<int, int>> Q;
        Q.emplace(headID, 0);
        int mins = 0;
        while (!Q.empty()) {
            int curr = Q.front().first;
            int time = Q.front().second;
            Q.pop();
            mins = max(mins, time);
            for (int e : table[curr]) {
                Q.emplace(e, time + informTime[curr]);
            }
        }
        
        return mins;
    }
};
