class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> candidates = {A[0], B[0]};
        for (int candidate : candidates) {
            int da = 0, db = 0;
            int i;
            for (i = 0; i < A.size(); ++i) {
                if (A[i] == candidate) {
                    if (B[i] != candidate) {
                        ++db;
                    }
                }
                else if (B[i] == candidate) {
                    ++da;
                }
                else {
                    break;
                }
            }
            if (i == A.size()) {
                return min(da, db);
            }
        }
        
        return -1;
    }
};
