class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, vector<string>> first, last;
        set<string> result;
        for (string p : phrases) {
            auto index1 = p.rfind(' ');
            string la = (index1 != string::npos) ? p.substr(index1 + 1) : p;
            for (string w : first[la]) {
                result.insert(p + w);
            }
            auto index2 = p.find(' ');
            string fi = (index2 != string::npos) ? p.substr(0, index2) : p;
            for (string w : last[fi]) {
                result.insert(w + p);
            }
            
            if (index1 != string::npos) {
                last[la].push_back(p.substr(0, index1 + 1));
            }
            else {
                last[la].push_back("");
            }
            if (index2 != string::npos) {
                first[fi].push_back(p.substr(index2));
            }
            else {
                first[fi].push_back("");
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};
