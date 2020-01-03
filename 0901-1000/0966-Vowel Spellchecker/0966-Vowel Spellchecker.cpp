class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> raw;
        unordered_map<string, string> cap, vowel;
        string v = "aeiou";
        for (string& word : wordlist) {
            raw.insert(word);
            string word2, word3;
            for (char c : word) {
                char cl = tolower(c);
                word2 += cl;
                if (v.find(cl) != string::npos) {
                    word3 += '#';
                }
                else {
                    word3 += cl;
                }
                cap.insert({word2, word});
                vowel.insert({word3, word});
            }
        }
        
        vector<string> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            string query = queries[i];
            if (raw.count(query)) {
                result[i] = query;
            }
            else {
                string word2, word3;
                for (char c : query) {
                    char cl = tolower(c);
                    word2 += cl;
                    if (v.find(cl) != string::npos) {
                        word3 += '#';
                    }
                    else {
                        word3 += cl;
                    }
                }
                if (cap.count(word2)) {
                    result[i] = cap[word2];
                }
                else if (vowel.count(word3)) {
                    result[i] = vowel[word3];
                }
            }      
        }
        return result;
    }
};
