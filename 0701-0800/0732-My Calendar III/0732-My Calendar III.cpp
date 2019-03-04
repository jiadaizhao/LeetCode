class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++table[start];
        --table[end];
        int sum = 0;
        int maxCount = 0;
        for (auto t : table) {
            sum += t.second;
            maxCount = max(maxCount, sum);
        }
        return maxCount;
    }
    
private:
    map<int, int> table;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
