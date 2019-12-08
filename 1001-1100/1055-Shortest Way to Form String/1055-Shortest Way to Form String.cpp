class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> table;
        for (int i = 0; i < source.size(); ++i) {
            table[source[i]].push_back(i);
        }
        
        int i = 0, count = 1;
        for (char c : target) {
            if (!table.count(c)) {
                return -1;
            }
            
            auto& il = table[c];
            auto it = lower_bound(il.begin(), il.end(), i);
            if (it == il.end()) {
                ++count;
                i = il[0] + 1;
            }
            else {
                i = *it + 1;
            }
        }
        
        return count;
    }
};
