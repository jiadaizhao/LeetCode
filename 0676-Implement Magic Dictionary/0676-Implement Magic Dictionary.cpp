class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string s : dict)
        {
            words.insert(s);
            for (int i = 0; i < s.size(); ++i)
            {
                string sub = s.substr(0, i) + '*' + s.substr(i + 1);
                ++table[sub];
            }
        }
        
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        bool found = (words.find(word) != words.end());
        for (int i = 0; i < word.size(); ++i)
        {
            string sub = word.substr(0, i) + '*' + word.substr(i + 1);            
            if ((found && table[sub] > 1) || (!found && table[sub] >= 1))
            {
                return true;
            }
        }
        
        return false;
    }
    
private:
    unordered_set<string> words;
    unordered_map<string, int> table;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
