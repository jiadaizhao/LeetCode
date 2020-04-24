class Solution {
public:
    string entityParser(string text) {
        int start = 0, curr = 0;
        unordered_map<string, char> table{{"&quot;", '\"'}, {"&apos;", '\''},{"&amp;", '&'},
                                          {"&gt;", '>'}, {"&lt;", '<'}, {"&frasl;", '/'}};
        for (char c : text) {
            text[curr] = c;
            if (c == '&') {
                start = curr;
            }
            else if (c == ';') {
                string s = text.substr(start, curr - start + 1);
                if (table.count(s)) {
                    text[start] = table[s];
                    curr = start;
                }
                start = curr + 1;
            }
            ++curr;
        }
        
        text.resize(curr);
        return text;
    }
};
