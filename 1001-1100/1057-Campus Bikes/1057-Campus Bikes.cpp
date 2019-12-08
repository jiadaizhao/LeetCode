class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int, int>>> distance(2001);
        for (int i = 0; i < workers.size(); ++i) {
            for (int j = 0; j < bikes.size(); ++j) {
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                distance[d].push_back({i, j});
            }
        }
        
        vector<int> result(workers.size(), -1);
        vector<bool> assigned(bikes.size());
        for (int d = 1; d <= 2000; ++d) {
            for (int i = 0; i < distance[d].size(); ++i) {
                int wi = distance[d][i].first;
                int bi = distance[d][i].second;
                if (result[wi] == -1 && !assigned[bi]) {
                    result[wi] = bi;
                    assigned[bi] = true;
                }
            }
        }
        
        return result;
    }
};
