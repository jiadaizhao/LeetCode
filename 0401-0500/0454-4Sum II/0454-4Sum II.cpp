class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> table;
        for (int a : A) {
            for (int b : B) {
                ++table[a + b];
            }
        }
        
        int count = 0;
        for (int c : C) {
            for (int d : D) {
                count += table[-c-d];
            }
        }
        
        return count;
    }
};
