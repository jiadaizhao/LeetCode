class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (int a : A) {
            if ((a & 1) == 0) {
                sum += a;
            }
        }
        
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int val = queries[i][0];
            int index = queries[i][1];
            if (A[index] & 1) {
                if (val & 1) {
                    sum += A[index] + val;
                }
            }
            else {
                if (val & 1) {
                    sum -= A[index];
                }
                else {
                    sum += val;
                }
            }
            A[index] += val;
            result[i] = sum;
        }
        
        return result;
    }
};
