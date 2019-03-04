class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        int i = 0, n = buildings.size();
        priority_queue<pair<int, int>> live;
        int x;
        while (i < n || !live.empty()) {
            if (live.empty() || (i < n && buildings[i][0] <= live.top().second)) {
                x = buildings[i][0];
                while (i < n && buildings[i][0] == x) {
                    live.emplace(buildings[i][2], buildings[i][1]);
                    ++i;
                }
            }
            else {
                x = live.top().second;
                while (!live.empty() && live.top().second <= x) {
                    live.pop();
                }                
            }
            int height = live.empty() ? 0 : live.top().first;
            if (result.size() == 0 || height != result.back().second) {
                result.emplace_back(x, height);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        int n = buildings.size();
        if (n == 0) {
            return result;
        }
        
        vector<Cell> points;
        for (auto b : buildings) {
            points.emplace_back(b[0], b[2], 1);
            points.emplace_back(b[1], b[2], 0);
        }
        
        sort(points.begin(), points.end());
        
        int last = 0;
        int prev = 0;
        multiset<int> heights;
        for (auto& c : points) {
            if (heights.empty()) {
                last = c.x;
                if (prev && c.x > prev) {
                    result.push_back({prev, 0});
                }
            }
            
            if (!heights.empty() && (*heights.rbegin()) <= c.h && last < c.x) {
                // Create new segment, otherwise update previous segment end.
                // last is segment start, prev is segment end.
                if (!(result.size() && result.back().second == (*heights.rbegin()) && prev == last)) {
                    result.push_back({last, *heights.rbegin()});
                }
                prev = c.x;
                last = c.x;
            }
            
            if (c.isStart == 1) {
                heights.insert(c.h);
            }
            else {
                heights.erase(heights.lower_bound(c.h));
            }
        }
        
        if (prev) {
            result.push_back({prev, 0});
        }
        
        return result;
    }
    
private:
    struct Cell {
        int x;
        int h;
        int isStart;
        Cell (int _x, int _h, int start): x(_x), h(_h), isStart(start){}
        bool operator < (const Cell &c) const {
            return x < c.x || x == c.x && isStart < c.isStart;
        }
    };
};
