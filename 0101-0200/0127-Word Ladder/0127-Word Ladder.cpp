class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> table;
        int L = beginWord.size();
        for (string word : wordList) {
            for (int i = 0; i < L; ++i) {
                table[word.substr(0, i) + '*' + word.substr(i + 1)].push_back(word);
            }
        }
        
        int step = 1;
        queue<string> Q;
        Q.push(beginWord);
        unordered_set<string> visited{beginWord};
        while (!Q.empty()) {
            int qs = Q.size();
            ++step;
            for (int k = 0; k < qs; ++k) {
                string s = Q.front();
                Q.pop();
                
                for (int i = 0; i < L; ++i) {
                    string nextWord = s.substr(0, i) + '*' + s.substr(i + 1);
                    for (string word : table[nextWord]) {
                        if (word == endWord) {
                            return step;
                        }
                        if (!visited.count(word)) {
                            Q.push(word);
                            visited.insert(word);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        unordered_map<string, vector<string>> table;
        int L = beginWord.size();
        for (string word : wordList) {
            for (int i = 0; i < L; ++i) {
                table[word.substr(0, i) + '*' + word.substr(i + 1)].push_back(word);
            }
        }
        
        int step = 1;
        unordered_set<string> visitedBegin{beginWord}, visitedEnd{endWord};
        unordered_set<string> visited{beginWord, endWord};
        while (!visitedBegin.empty() && !visitedEnd.empty()) {
            if (visitedBegin.size() > visitedEnd.size()) {
                swap(visitedBegin, visitedEnd);
            }
            
            ++step;
            unordered_set<string> temp;
            for (string w : visitedBegin) {
                for (int i = 0; i < L; ++i) {
                    string nw = w.substr(0, i) + '*' + w.substr(i + 1);
                    for (string word : table[nw]) {
                        if (visitedEnd.count(word)) {
                            return step;
                        }
                        if (!visited.count(word)) {
                            temp.insert(word);
                            visited.insert(word);
                        }
                    }
                }
            }
            visitedBegin = std::move(temp);
        }
        
        return 0;
    }
};
