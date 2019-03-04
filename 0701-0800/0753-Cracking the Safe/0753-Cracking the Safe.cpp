class Solution {
public:
    string crackSafe(int n, int k) {
        string res = string(n, '0');
        unordered_set<string> visited;
        visited.insert(res);
        int limit = pow(k, n);
        for (int i = 0; i < limit; ++i) {
            string prev = res.substr(res.size() - n + 1);
            for (int j = k - 1; j >= 0; --j) {
                char c = '0' + j;
                string curr = prev + c;
                if (visited.find(curr) == visited.end()) {
                    visited.insert(curr);
                    res += '0' + j;
                    break;
                }
            }
        }
        
        return res;
    }
};
