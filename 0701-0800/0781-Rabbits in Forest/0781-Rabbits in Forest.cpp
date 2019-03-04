class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> table;
        for (int a : answers) {
            ++table[a];
        }
        int count = 0;
        for (auto t : table) {
            // round up t.second to multiple times of (t.first + 1)
            count += (t.second + t.first) / (t.first + 1) * (t.first + 1);
        }
        return count;
    }
};
