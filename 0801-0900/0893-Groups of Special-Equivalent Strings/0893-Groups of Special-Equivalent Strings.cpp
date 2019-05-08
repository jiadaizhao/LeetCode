class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> table;
        for (string& a : A) {
            string even, odd;
            for (int i = 0; i < a.size(); ++i) {
                if (i & 1) {
                    odd += a[i];
                }
                else {
                    even += a[i];
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            table.insert(even + odd);
        }
        return table.size();
    }
};
