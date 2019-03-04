class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> wordSet;
        for (string s : wordList) {
            wordSet.insert(s);
        }
        
        if (wordSet.find(endWord) == wordSet.end()) {
            return result;
        }
        
        if (!bfs(beginWord, endWord, wordSet)) {
            return result;
        }
        
        vector<string> path;
        path.push_back(beginWord);
        dfs(beginWord, endWord, path, result);
        return result;
    }

private:
    unordered_map<string, vector<string>> nextWord;
    unordered_map<string, int> distance;
    bool bfs(string beginWord, string endWord, unordered_set<string>& wordSet) {
        queue<string> Q;
        Q.push(beginWord);
        distance[beginWord] = 0;
        int len = 0;
        while (!Q.empty()) {
            ++len;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                string word = Q.front();
                Q.pop();
                if (word == endWord) {
                    return true;
                }
                for (int j = 0; j < word.size(); ++j) {
                    string newWord(word);
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (word[j] == c) {
                            continue;
                        }
                        
                        newWord[j] = c;
                        if (wordSet.find(newWord) == wordSet.end()) {
                            continue;
                        }
                        
                        if (distance.find(newWord) == distance.end()) {
                            Q.push(newWord);
                            distance[newWord] = len;
                        }
                        
                        nextWord[word].push_back(newWord);
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
        
        auto nw = nextWord[beginWord];
        for (string s : nw) {
            if (distance[s] == distance[beginWord] + 1) {
                path.push_back(s);
                dfs(s, endWord, path, result);
                path.pop_back();
            }
        }
    }
};
