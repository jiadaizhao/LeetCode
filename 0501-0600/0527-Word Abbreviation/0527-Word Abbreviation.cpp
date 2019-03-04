class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, int> table;
        int n = dict.size();
        vector<string> result(n);
        vector<int> prev(n, 1);
        for (int i = 0; i < dict.size(); ++i) {
            string str = getAbbreviation(dict[i], 1);
            result[i] = str;
            ++table[str];
        }
        
        bool unique;
        do {
            unique = true;
            for (int i = 0; i < n; ++i) {
                if (table[result[i]] > 1) {
                    unique = false;
                    ++prev[i];
                    string str = getAbbreviation(dict[i], prev[i]);
                    result[i] = str;
                    ++table[str];
                }
            }
        } while(!unique);
        
        return result;
    }
    
private:
    string getAbbreviation(string& s, int prev) {
        if (prev >= (int)(s.size()) - 2) {
            return s;
        }
        
        return s.substr(0, prev) + to_string(s.size() - 1 - prev) + s.back();
    }
};
