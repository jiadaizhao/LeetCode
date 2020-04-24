class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> table;
        for (char c : s) {
            ++table[c];
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto& p : table) {
            pq.push({p.second, p.first});
        }
        
        string result;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            result += string(p.first, p.second);
        }
        
        return result;
    }
};
