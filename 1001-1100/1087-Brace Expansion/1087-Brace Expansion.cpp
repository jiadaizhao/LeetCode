class Solution {
public:
    vector<string> expand(string S) {
        vector<string> result;
        string path;
        dfs(S, 0, path, result);
        return result;
    }
    
private:
    void dfs(string& S, int start, string path, vector<string>& result) {
        if (start == S.size()) {
            result.push_back(path);
            return;
        }
        
        if (S[start] == '{') {
            int index = -1;
            vector<char> options;
            for (int i = start + 1; i < S.size(); ++i) {
                if (S[i] == '}') {
                    index = i;
                    break;
                }
                else if (S[i] != ',') {
                    options.push_back(S[i]);
                }
            }

            sort(options.begin(), options.end());
            for (char c : options) {
                dfs(S, index + 1, path + c, result);
            }
        }
        else {
            dfs(S, start + 1, path + S[start], result);
        }
    }
};
