class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int num = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] <= A[i - 1]) {
                num += A[i - 1] + 1 - A[i];
                A[i] = A[i - 1] + 1;
            }
        }
        return num;
    }
};

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int, int> table;
        for (int a : A) {
            ++table[a];
        }
        
        int need = 0, num = 0;
        for (auto p : table) {
            num += max(need - p.first, 0) * p.second + p.second * (p.second - 1) / 2;
            need = max(need, p.first) + p.second;
        }
        return num;
    }
};
