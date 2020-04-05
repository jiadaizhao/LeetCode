class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = table.lower_bound(val);
        if (it != table.begin()) {
            --it;
            if (it->second < val - 1) {
                ++it;
            }
        }
        int start = val, end = val;
        while (it != table.end() && it->first <= val + 1 && it->second >= val - 1) {
            start = min(start, it->first);
            end = max(end, it->second);
            it = table.erase(it);
        }
        table[start] = end;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto p : table) {
            result.push_back({p.first, p.second});
        }
        return result;
    }
    
private:
    map<int, int> table;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto l = table.lower_bound(val);
        if (l != table.begin()) {
            --l;
            if (l->second < val - 1) {
                ++l;
            }
        }
        auto r = table.upper_bound(val + 1);
        int left = val, right = val;
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            table.erase(l, ++r);
        }
        table[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto p : table) {
            result.push_back({p.first, p.second});
        }
        return result;
    }
    
private:
    map<int, int> table;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
