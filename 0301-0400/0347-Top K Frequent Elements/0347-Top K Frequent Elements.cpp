class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        for (int num : nums) {
            ++table[num];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto t : table) {
            pq.emplace(t.first, t.second);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = pq.top().first;
            pq.pop();
        }
        return result;
    }
    
private:
    struct cmp {
        bool operator () (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        }    
    };
};
