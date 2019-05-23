class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        map<int, int> table;
        int count = 1;
        vector<bool> odd(A.size()), even(A.size());
        odd.back() = even.back() = true;
        for (int i = A.size() - 1; i >= 0; --i) {
            auto l = table.lower_bound(A[i]);
            if (l != table.end()) {
                if (even[l->second]) {
                    odd[i] = true;
                    ++count;
                }
                if (l->first == A[i]) {
                    ++l;
                }
            }

            if (l != table.begin()) {
                if (odd[(--l)->second]) {
                    even[i] = true;
                }
            }

            table[A[i]] = i;
        }

        return count;
    }
};
