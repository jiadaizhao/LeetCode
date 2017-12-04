class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if (k <= 0 || nums.size() == 0) {
            return result;
        }
        
        unordered_map<int, int> table;
        for (int num : nums) {
            ++table[num];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto it = table.begin(); it != table.end(); ++it) {
            if (pq.size() < k) {
                pq.push(*it);
            }
            else if ((pq.top().second < it->second) || (pq.top().second == it->second && pq.top().first > it->first)) {
                pq.pop();
                pq.push(*it);
            }
        }
        
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    struct cmp {
        bool operator() (pair<int, int> p1, pair<int, int> p2) {
            if (p1.second == p2.second) {
                return p1.first < p2.first;
            }
            else {
                return p1.second > p2.second;
            }
        }
    };
};
