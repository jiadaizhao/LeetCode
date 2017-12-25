class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> table;
        for (string& word : words) {
            ++table[word];
        }
        
        priority_queue<Node> pq;
        for (auto t : table) {
            pq.emplace(t.first, t.second);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = pq.top().s;
            pq.pop();
        }
        
        return result;        
    }
    
private:
    struct Node {
        string s;
        int count;
        Node(string str, int c): s(str), count(c){}
        bool operator < (const Node& node) const {
            if (count == node.count) {
                return s < node.s;
            }
            return count > node.count;
        }
    };
};
