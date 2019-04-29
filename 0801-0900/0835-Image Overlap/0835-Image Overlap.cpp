class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<int> A1, B1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    A1.push_back(i * n * 2 + j);
                }
                
                if (B[i][j] == 1) {
                    B1.push_back(i * n * 2 + j);
                }
            }
        }
        
        unordered_map<int, int> table;
        for (int a : A1) {
            for (int b : B1) {
                ++table[a - b];
            }
        }
        
        int result = 0;
        for (auto t : table) {
            result = max(result, t.second);
        }
            
        return result;
    }
};
