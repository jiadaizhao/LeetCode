class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        vector<vector<vector<int>>> matrix(7, vector<vector<int>>(7, vector<int>()));
        for (string s : allowed) {
            matrix[s[0] - 'A'][s[1] - 'A'].push_back(s[2] - 'A');
        }
                
        return dfs(bottom, 0, "", matrix);
    }
    
private:
    unordered_map<string, bool> cache;
    bool dfs(string s, int start, string path, vector<vector<vector<int>>>& matrix) {       
        if (start == s.size() - 1) {
            if (s.size() == 2) {
                return cache[s] = true;
            }
            if (cache.find(path) != cache.end()) {
                return cache[path];
            }
            
            return cache[path] = dfs(path, 0, "", matrix);
        }
        
        for (int i : matrix[s[start] - 'A'][s[start + 1] - 'A']) {
            if (dfs(s, start + 1, path + (char)('A' + i), matrix)) {
                return cache[s] = true;
            }
        }

        return cache[s] = false;
    }
};
