class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(1 + N, vector<int>(0));
        for (auto& d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        for (int i = 1; i <= N; ++i) {
            if (!colors.count(i) && !dfs(graph, i, 0)) {
                return false;
            }
        }

        return true;
    }

private:
    unordered_map<int, int> colors;
    bool dfs(vector<vector<int>>& graph, int curr, int color) {
        colors[curr] = color;
        for (int next : graph[curr]) {
            if (!colors.count(next)) {
                if (!dfs(graph, next, color ^ 1)) {
                    return false;
                }
            }
            else if (colors[curr] == colors[next]) {
                return false;
            }
        }
        return true;
    }
};
