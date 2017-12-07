class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, capCmp> cappq;
        for (int i = 0; i < Capital.size(); ++i) {
            cappq.emplace(i, Capital[i]);
        }
        
        priority_queue<int> profitpq;
        while (k--) {
            while (!cappq.empty() && cappq.top().second <= W) {
                int i = cappq.top().first;
                cappq.pop();
                profitpq.push(Profits[i]);
            }
            
            if (!profitpq.empty()) {
                int val = profitpq.top();
                profitpq.pop();
                W += val;
            }
        }
        
        return W;
    }
    
private:
    struct capCmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        }
    };
};
