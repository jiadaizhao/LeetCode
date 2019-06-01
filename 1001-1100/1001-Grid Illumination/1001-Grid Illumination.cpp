struct pairhash {
    size_t operator()(const pair<int, int> &p) const {
        return p.first ^ p.second;
    }
};

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> xm, ym, diag, anti;
        unordered_set<pair<int, int>, pairhash> locations;
        for (auto& lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            ++xm[x];
            ++ym[y];
            ++diag[x - y];
            ++anti[x + y];
            locations.insert({x, y});
        }
        
        vector<int> result(queries.size());
        int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        for (int i = 0; i < queries.size(); ++i) {
            int x = queries[i][0], y = queries[i][1];
            if (xm[x] || ym[y] || diag[x - y] || anti[x + y]) {
                result[i] = 1;
                for (int k = 0; k < 9; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && locations.erase({nx, ny})) {
                        --xm[nx];
                        --ym[ny];
                        --diag[nx - ny];
                        --anti[nx + ny];
                    }
                }
            }
        }
        
        return result;      
    }
};
