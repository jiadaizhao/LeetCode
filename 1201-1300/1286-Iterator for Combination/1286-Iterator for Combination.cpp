class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        string path;
        dfs(characters, 0, combinationLength, path, result);
        reverse(result.begin(), result.end());
    }
    
    string next() {
        string s = result.back();
        result.pop_back();
        return s;
    }
    
    bool hasNext() {
        return !result.empty();
    }
    
private:
    vector<string> result;
    void dfs(string characters, int start, int combinationLength, string& path, vector<string>& result) {
        int curr = path.size();
        if (curr == combinationLength) {
            result.push_back(path);
            return;
        }
        
        int diff = combinationLength - curr;
        for (int i = start; i <= characters.size() - diff; ++i) {
            path.push_back(characters[i]);
            dfs(characters, i + 1, combinationLength, path, result);
            path.pop_back();
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
