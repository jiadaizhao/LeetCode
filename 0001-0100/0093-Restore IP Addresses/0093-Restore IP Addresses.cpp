class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string path;
        dfs(s, 0, 0, path, result);
        return result;
    }
    
private:
    void dfs(string& s, int start, int count, string path, vector<string>& result) {
        if (count == 4) {
            if (start == s.size()) {
                result.push_back(path);
            }
            return;
        }
        
        if (path != "") {
            path += '.';
        }
        
        for (int i = start, j = 1; i < s.size() && j <= 3; ++i, ++j) {
            string temp = s.substr(start, i - start + 1);
            if (stoi(temp) >= 0 && stoi(temp) <= 255 && (temp.size() == 1 || temp[0] != '0')) {
                dfs(s, i + 1, count + 1, path + temp, result);
            }
        }
    }
};
