class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int num = 1;
        while (!St.empty() && price >= St.top().first) {
            num += St.top().second;
            St.pop();
        }
        St.emplace(price, num);
        return num;
    }

private:
    stack<pair<int, int>> St;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
