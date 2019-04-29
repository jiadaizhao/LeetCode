class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        int n = S.size();        
        for (int i = 1; i <= min(10, n / 2); ++i) {
            string s1 = S.substr(0, i);
            if (i > 1 && s1[0] == '0') {
                break;
            }
            int num1 = stol(s1);
            for (int j = 1; j <= min(10, n / 2); ++j) {
                if (n - i - j < max(i, j)) {
                    break;
                }
                
                string s2 = S.substr(i, j);
                if (j > 1 && s2[0] == '0') {
                    break;
                }
                int num2 = stol(s2);
                vector<int> path = {num1, num2};
                if (dfs(S, i + j, path, num1, num2)) {
                    return path;
                }
            }
        }
        
        return {};
    }

private:
    bool dfs(string& S, int start, vector<int>& path, int num1, int num2) {
        if (start == S.size()) {
            return true;
        }
        
        long long sum = (long long)num1 + num2;
        if (sum > INT_MAX) {
            return false;
        }
        string ss = to_string(sum);
        string s3 = S.substr(start, ss.size());
        if (ss != s3) {
            return false;
        }
        else {
            path.push_back(sum);
            return dfs(S, start + ss.size(), path, num2, sum);
        }
    }
};
