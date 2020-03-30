class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.size();
        for (string word : wordList) {
            for (int i = 0; i < L; ++i) {
                table[word.substr(0, i) + '*' + word.substr(i + 1)].push_back(word);
            }
        }
        vector<vector<string>> result;
        
        if (!bfs(beginWord, endWord)) {
            return result;
        }
        
        vector<string> path = {beginWord};
        dfs(beginWord, endWord, path, result);
        return result;
    }
    
private:
    unordered_map<string, vector<string>> table;
    unordered_map<string, vector<string>> nextWord;
    unordered_map<string, int> distance;
    bool bfs(string beginWord, string endWord) {
        int step = 0, L = beginWord.size();
        queue<string> Q;
        Q.push(beginWord);
        distance[beginWord] = 0;
        while (!Q.empty()) {
            ++step;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                string s = Q.front();
                if (s == endWord) {
                    return true;
                }
                Q.pop();
                for (int i = 0; i < L; ++i) {
                    string nw = s.substr(0, i) + '*' + s.substr(i + 1);
                    for (string word : table[nw]) {
                        if (!distance.count(word)) {
                            Q.push(word);
                            distance[word] = step;
                        }
                        nextWord[s].push_back(word);
                    }
                }
            }            
        }
        
        return false;
    }
    
    void dfs(string beginWord, string endWord, vector<string>& path, vector<vector<string>>& result) {
        if (beginWord == endWord) {
            result.push_back(path);
            return;
        }
        
        for (string word : nextWord[beginWord]) {
            if (distance[word] == distance[beginWord] + 1) {
                path.push_back(word);
                dfs(word, endWord, path, result);
                path.pop_back();
            }
        }
    }
};
