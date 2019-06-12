class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N, vector<int>(0));
        for (auto& path : paths) {
            graph[path[0] - 1].push_back(path[1]);
            graph[path[1] - 1].push_back(path[0]);
        }
        
        vector<int> garden(N);
        for (int i = 0; i < N; ++i) {
            vector<bool> used(5);
            for (int neighbor : graph[i]) {
                used[garden[neighbor - 1]] = true;
            }
            
            for (int color = 1; color < 5; ++color) {
                if (!used[color]) {
                    garden[i] = color;
                    break;
                }
            }
        }
        
        return garden;
    }
};
