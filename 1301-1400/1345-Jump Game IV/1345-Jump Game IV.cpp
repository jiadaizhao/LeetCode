class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> table;
        for (int i = 0; i < arr.size(); ++i) {
            table[arr[i]].push_back(i);
        }
        
        vector<bool> visited(arr.size());
        queue<int> Q;
        Q.push(0);
        visited[0] = true;
        int step = 0;
        while (!Q.empty()) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int curr = Q.front();
                if (curr == arr.size() - 1) {
                    return step;
                }
                Q.pop();
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    Q.push(curr - 1);
                    visited[curr - 1] = true;
                }
                if (curr + 1 < arr.size() && !visited[curr + 1]) {
                    Q.push(curr + 1);
                    visited[curr + 1] = true;
                }
                for (int next : table[arr[curr]]) {
                    if (!visited[next]) {
                        Q.push(next);
                        visited[next] = true;
                    }
                }
                table[arr[curr]].clear();
            }
            ++step;
        }
        
        return step;
    }
};
