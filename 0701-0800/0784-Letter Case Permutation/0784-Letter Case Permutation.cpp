class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string path;
        dfs(S, 0, path, result);
        return result;
    }
    
private:
    void dfs(string& s, int start, string& path, vector<string>& result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        
        if (isdigit(s[start])) {
            path += s[start];
            dfs(s, start + 1, path, result);
            path.pop_back();
        }
        else {
            path += tolower(s[start]);
            dfs(s, start + 1, path, result);
            path.pop_back();
            
            path += toupper(s[start]);
            dfs(s, start + 1, path, result);
            path.pop_back();
        }
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        int count = 0;
        for (char c : S) {
            if (!isdigit(c)) ++count;
        }
        int upper = 1 << count;
        for (int i = 0; i < upper; ++i) {
            string s;
            int b = 0;
            for (char c : S) {
                if (isdigit(c)) {
                    s += c;
                }
                else {
                    if ((i >> b++) & 1) {
                        s += toupper(c);
                    }
                    else {
                        s += tolower(c);
                    }
                }
            }
            result.push_back(s);
        }
        return result;
    }
};
