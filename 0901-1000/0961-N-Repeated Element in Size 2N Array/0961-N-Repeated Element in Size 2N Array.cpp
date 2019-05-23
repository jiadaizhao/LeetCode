class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] == A[i - 1] || A[i] == A[i - 2]) {
                return A[i];
            }
        }
        return A[0];
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int i, j, n = A.size();
        do {
            i = rand() % n;
            j = rand() % n;
        } while(i == j || A[i] != A[j]);
            
        return A[i];
    }
};
