class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int n = B.size();
        unordered_map<int, int> table;
        for (int i = 0; i < n; ++i) {
            table[B[i]] = i;
        }
        
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = table[A[i]];
        }
        
        return result;
    }
};
