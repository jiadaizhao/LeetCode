/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        vector<Interval> intervals;
        for (auto a : avails) {
            for (Interval i : a) {
                intervals.push_back(i);
            }
        }
        
        sort(intervals.begin(), intervals.end(), cmp());
        int prevEnd = intervals[0].end;        
        vector<Interval> result;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > prevEnd) {
                result.push_back({prevEnd, intervals[i].start});
            }
                        
            if (intervals[i].end > prevEnd) {
                prevEnd = intervals[i].end;
            }
        }
        
        return result;
    }
    
private:
    struct cmp {
        bool operator() (Interval& i1, Interval& i2) {
            return i1.start < i2.start;
        }    
    };
};


class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        priority_queue<Node> pq;
        int prevStart = avails[0][0].start, prevEnd = avails[0][0].end;
        for (int i = 0; i < avails.size(); ++i) {
            if (avails[i][0].start < prevStart) {
                prevStart = avails[i][0].start;
                prevEnd = avails[i][0].end;
            }
            pq.emplace(i, 0, avails[i][0].start, avails[i][0].end);
        }
        
        vector<Interval> result;
        while (!pq.empty()) {
            Node node = pq.top();
            pq.pop();
            if (node.start > prevEnd) {
                result.push_back({prevEnd, node.start});
            }
            
            if (node.end > prevEnd) {
                prevEnd = node.end;    
            }
            
            int col = node.col;
            if (col < avails[node.row].size() - 1) {
                ++col;
                pq.emplace(node.row, col, avails[node.row][col].start, avails[node.row][col].end);
            }
        }
        
        return result;
    }
    
private:
    struct Node {
        int row;
        int col;
        int start;
        int end;
        Node(int r, int c, int s, int e): row(r), col(c), start(s), end(e) {}
        bool operator < (const Node& node) const {
            return start > node.start;
        }
    };
};