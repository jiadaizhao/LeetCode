class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> table;
        for (int d : deck) {
            ++table[d];
        }
        int curr = 0;
        for (auto t : table) {
            curr = __gcd(curr, t.second);
            if (curr < 2) {
                return false;
            }
        }
        return true;
    }
};
