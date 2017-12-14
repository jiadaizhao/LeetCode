class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> bold(s.size());
        for (string str : dict) {
            for (int i = 0; i < int(s.size()) - int(str.size()) + 1; ++i) {
                if (str == s.substr(i, str.size())) {
                    for (int j = i; j < i + str.size(); ++j) {
                        bold[j] = true;
                    }
                }
            }
        }
        
        string result;
        int i = 0;
        while (i < bold.size()) {
            if (bold[i]) {
                result += "<b>";
                while (i < bold.size() && bold[i]) {
                    result += s[i++];
                }
                result += "</b>";
            }
            else {
                result += s[i++];
            }
        }
        return result;        
    }
};
