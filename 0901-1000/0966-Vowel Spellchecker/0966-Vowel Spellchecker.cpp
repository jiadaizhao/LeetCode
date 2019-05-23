class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> table1;
        unordered_map<string, string> table2, table3;
        string vowel = "aeiou";
        for (string& word : wordlist) {
            table1.insert(word);
            string word2, word3;
            for (char c : word) {
                char cl = tolower(c);
                word2 += cl;
                if (vowel.find(cl) != string::npos) {
                    word3 += '#';
                }
                else {
                    word3 += cl;
                }
                table2.insert({word2, word});
                table3.insert({word3, word});
            }
        }
        
        vector<string> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            string query = queries[i];
            if (table1.count(query)) {
                result[i] = query;
            }
            else {
                string word2, word3;
                for (char c : query) {
                    char cl = tolower(c);
                    word2 += cl;
                    if (vowel.find(cl) != string::npos) {
                        word3 += '#';
                    }
                    else {
                        word3 += cl;
                    }
                }
                if (table2.count(word2)) {
                    result[i] = table2[word2];
                }
                else if (table3.count(word3)) {
                    result[i] = table3[word3];
                }
            }      
        }
        return result;
    }
};
