class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> rg(n), bg(n);
        for (int i = 0; i < red_edges.size(); ++i) {
            rg[red_edges[i][0]].push_back(red_edges[i][1]);
        }
        for (int i = 0; i < blue_edges.size(); ++i) {
            bg[blue_edges[i][0]].push_back(blue_edges[i][1]);
        }
        
        queue<pair<int, bool>> Q;
        Q.emplace(0, true);
        Q.emplace(0, false);
        vector<int> red(n, -1), blue(n, -1);
        red[0] = 0;
        blue[0] = 0;
        int step = 0;
        while (!Q.empty()) {
            ++step;
            int qs = Q.size();
            for (int k = 0; k < qs; ++k) {
                int i = Q.front().first;
                int lastRed = Q.front().second;
                Q.pop();
                if (lastRed) {
                    for (int j : bg[i]) {
                        if (blue[j] == -1) {
                            blue[j] = step;
                            Q.emplace(j, false);
                        }
                    }
                }
                else {
                    for (int j : rg[i]) {
                        if (red[j] == -1) {
                            red[j] = step;
                            Q.emplace(j, true);
                        }
                    }
                }
            }
        }
        
        vector<int> answer(n);
        for (int i = 1; i < n; ++i) {
            if (red[i] != -1) {
                answer[i] = (blue[i] != -1) ? min(red[i], blue[i]) : red[i];
            }
            else {
                answer[i] = blue[i];
            }
        }
        return answer;
    }
};
