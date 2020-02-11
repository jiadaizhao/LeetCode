class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> table;
        for (int a : arr) {
            ++table[a];
        }
        
        multiset<int> count;
        for (auto p : table) {
            count.insert(p.second);
        }
        int minSize = 0, remove = 0;
        for (auto it = count.rbegin(); remove * 2 < arr.size(); ++it) {
            ++minSize;
            remove += *it;
        }
        return minSize;
    }
};
