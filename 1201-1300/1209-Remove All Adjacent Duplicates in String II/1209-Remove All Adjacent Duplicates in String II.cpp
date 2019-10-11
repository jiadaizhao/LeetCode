class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> St;
        for (char c : s) {
            if (St.size() && St.back().first == c) {
                ++St.back().second;
                if (St.back().second == k) {
                    St.pop_back();
                }
            }
            else {
                St.push_back({c, 1});
            }
        }

        string result;
        for (auto p : St) {
            result += string(p.second, p.first);
        }

        return result;
    }
};
