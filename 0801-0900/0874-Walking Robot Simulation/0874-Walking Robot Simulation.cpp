struct pairhash {
    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pairhash> obs;
        for (auto ob : obstacles) {
            obs.insert({ob[0], ob[1]});
        }
        
        int maxDist = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obs.find({nx, ny}) == obs.end()) {
                        x = nx;
                        y = ny;
                        maxDist = max(maxDist, x * x + y * y);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return maxDist;
    }
};
