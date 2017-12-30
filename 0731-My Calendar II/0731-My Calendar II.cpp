class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++table[start];
        --table[end];
        int sum = 0;
        for (auto t : table) {
            sum += t.second;
            if (sum >= 3) {
                --table[start];
                ++table[end];
                return false;
            }
        }
        return true;
    }
    
private:
    map<int, int> table;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto& overlap : overlaps) {
            if (start < overlap.second && end > overlap.first) {
                return false;
            }
        }
        
        for (auto& b : books) {
            if (start < b.second && end > b.first) {
                overlaps.emplace_back(max(start, b.first), min(end, b.second));
            }
        }
        
        books.emplace_back(start, end);
        return true;
    }
    
private:
    vector<pair<int, int>> books;
    vector<pair<int, int>> overlaps;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
