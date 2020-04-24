class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> bit(m * 2 + 1);
        unordered_map<int, int> table;
        for (int i = 1; i <= m; ++i) {
            update(bit, m + i, 1);
            table[i] = m + i;
        }
        
        vector<int> result;
        int curr = m;
        for (int q : queries) {
            result.push_back(read(bit, table[q]) - 1);
            update(bit, table[q], -1);
            update(bit, curr, 1);
            table[q] = curr--;
        }
        
        return result;
    }
    
private:
    int read(vector<int>& bit, int i) {
        int sum = 0;
        while (i >0) {
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }
    
    void update(vector<int>& bit, int i, int val) {
        while (i < bit.size()) {
            bit[i] += val;
            i += i & (-i);
        }
    }
};
