class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int count = 0;
        int n = row.size();
        
        unordered_map<int, int> table;
        for (int i = 0; i < n; ++i) {
            table[row[i]] = i;
        }
                
        for (int i = 0; i < n; i += 2) {
            int curr = row[i];
            int couple = curr ^ 1;
            if (table[couple] == i + 1) {
                continue;
            }
            
            ++count;
            table[row[i + 1]] = table[couple];
            swap(row[i + 1], row[table[couple]]);
            table[couple] = i + 1;
        }
        return count;
    }
};
