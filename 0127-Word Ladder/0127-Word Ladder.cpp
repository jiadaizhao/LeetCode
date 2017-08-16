class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (string s : wordList)
        {
            wordSet.insert(s);
        }
        
        if (wordSet.find(endWord) == wordSet.end())
        {
            return 0;
        }
        
        unordered_set<string> visited;
        queue<string> Q;
        Q.push(beginWord);
        visited.insert(beginWord);
        int len = 0;
        while (!Q.empty())
        {
            ++len;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i)
            {
                string word = Q.front();
                if (word == endWord)
                {
                    return len;
                }
                Q.pop();
                for (int j = 0; j < word.size(); ++j)
                {
                    string newWord(word);
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (word[j] == c)
                        {
                            continue;
                        }
                        
                        newWord[j] = c;
                        if (wordSet.find(newWord) == wordSet.end())
                        {
                            continue;
                        }
                        
                        if (visited.find(newWord) == visited.end())
                        {
                            Q.push(newWord);
                            visited.insert(newWord);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};
