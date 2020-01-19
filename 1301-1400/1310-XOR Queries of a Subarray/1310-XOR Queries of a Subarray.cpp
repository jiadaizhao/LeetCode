class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> preXor(1 + arr.size()), result(queries.size());
        for (int i = 1; i < preXor.size(); ++i) {
            preXor[i] = preXor[i - 1] ^ arr[i - 1];
        }
        
        for (int i = 0; i < queries.size(); ++i) {
            result[i] = preXor[queries[i][1] + 1] ^ preXor[queries[i][0]];
        }
        
        return result;
    }
};
