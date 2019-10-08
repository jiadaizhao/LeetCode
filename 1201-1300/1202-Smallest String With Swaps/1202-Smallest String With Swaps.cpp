class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> parent(s.size());
        for (int i = 0; i < s.size(); ++i) {
            parent[i] = i;
        }

        for (auto p : pairs) {
            int pa = findParent(parent, p[0]);
            int pb = findParent(parent, p[1]);
            if (pa != pb) {
                parent[pb] = pa;
            }
        }

        unordered_map<int, vector<char>> table;
        for (int i = 0; i < s.size(); ++i) {
            table[findParent(parent, i)].push_back(s[i]);
        }

        for (auto& p : table) {
            sort(p.second.begin(), p.second.end(), greater<int>());
        }

        string result;
        for (int i = 0; i < s.size(); ++i) {
            int p = findParent(parent, i);
            char c = table[p].back();
            table[p].pop_back();
            result += c;
        }

        return result;
    }

private:
    int findParent(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }
};
