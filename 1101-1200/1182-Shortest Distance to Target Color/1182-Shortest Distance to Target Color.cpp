class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> dist(n, vector<int>(3, -1));
        dist[0][colors[0] - 1] = 0;
        for (int i = 1; i < n; ++i) {
            for (int c = 0; c < 3; ++c) {
                if (dist[i - 1][c] != -1) {
                    dist[i][c] = dist[i - 1][c] + 1;
                }
            }
            dist[i][colors[i] - 1] = 0;
        }
        
        for (int i = n - 2; i >= 0; --i) {
            for (int c = 0; c < 3; ++c) {
                if (dist[i + 1][c] != -1 && (dist[i][c] == -1 || dist[i + 1][c] + 1 < dist[i][c])) {
                    dist[i][c] = dist[i + 1][c] + 1;
                }
            }
        }
        
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            result[i] = dist[queries[i][0]][queries[i][1] - 1];
        }
        
        return result;
    }
};


class Solution2 {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> table(4);
        for (int i = 0; i < colors.size(); ++i) {
            table[colors[i]].push_back(i);
        }
        
        vector<int> result;
        for (auto& q : queries) {
            int i = q[0], c = q[1];
            if (table[c].size() > 0) {
                auto it = lower_bound(table[c].begin(), table[c].end(), i);
                if (it == table[c].begin()) {
                    result.push_back(*it - i);
                }
                else if (it == table[c].end()) {
                    result.push_back(i - table[c].back());
                }
                else {
                    int a = *it - i;
                    int b = i - *(--it);
                    result.push_back(min(a, b));
                }
            }
            else {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};
