class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            table[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int result = INT_MAX;
        vector<int> index1 = table[word1];
        vector<int> index2 = table[word2];
        int p1 = 0, p2 = 0;
        while (p1 < index1.size() && p2 < index2.size()) {
            result = min(result, abs(index1[p1] - index2[p2]));
            if (index1[p1] < index2[p2]) {
                ++p1;
            }
            else {
                ++p2;
            }
        }
        
        return result;
    }
private:
    unordered_map<string, vector<int>> table;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
 