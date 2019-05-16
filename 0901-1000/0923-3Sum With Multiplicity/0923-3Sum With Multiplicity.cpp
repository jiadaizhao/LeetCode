class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long long> table;
        for (int a : A) {
            ++table[a];
        }
        int total = 0, MOD = 1e9 + 7;
        for (auto it1 : table) {
            for (auto it2 : table) {
                int Ai = it1.first, Aj = it2.first, Ak = target - Ai - Aj;
                if (!table.count(Ak)) {
                    continue;
                }
                
                if (Ai == Aj) {
                    if (Aj == Ak) {
                        total = (total + table[Ai] * (table[Ai] - 1) * (table[Ai] - 2) / 6) % MOD;
                    }
                    else {
                        total = (total + table[Ai] * (table[Ai] - 1) / 2 * table[Ak]) % MOD;
                    }
                }
                else if (Ai < Aj && Aj < Ak) {
                    total = (total + table[Ai] * table[Aj] * table[Ak]) % MOD;
                }
            }
        }
        return total;
    }
};
