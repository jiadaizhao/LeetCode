class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> table;
        for (auto item : items) {
            table[item[0]].push(item[1]);
            if (table[item[0]].size() > 5) {
                table[item[0]].pop();
            }
        }
        
        vector<vector<int>> result;
        for (auto p : table) {
            int id = p.first;
            auto pq = p.second;
            int sum = 0, count = pq.size();            
            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            result.push_back({id, sum / count});
        }
        return result;
    }
};
