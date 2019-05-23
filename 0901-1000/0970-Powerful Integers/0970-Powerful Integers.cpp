class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        priority_queue<Cell> pq;
        pq.emplace(2, 1, 1);
        vector<int> result;
        while (!pq.empty()) {
            int sum = pq.top().sum;
            if (sum > bound) {
                break;
            }
            int first = pq.top().first;
            int second = pq.top().second;
            pq.pop();
            if (result.empty() || sum != result.back()) {
                result.push_back(sum);
            }
            
            if (x != 1) {
                pq.emplace(first*x + second, first*x, second);
            }
            if (y != 1) {
                pq.emplace(first + second*y, first, second*y);
            }
        }
        return result;
    }
    
private:
    struct Cell {
        int sum;
        int first;
        int second;
        Cell(int s, int fi, int se): sum(s), first(fi), second(se){}
        bool operator < (const Cell& cell) const {
            return sum > cell.sum;
        }
    };
};
