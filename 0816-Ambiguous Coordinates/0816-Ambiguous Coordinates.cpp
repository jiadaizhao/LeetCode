class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> result;
        int n = S.size();
        for (int i = 1; i < n - 2; ++i) {
            vector<string> result1 = parse(S.substr(1, i));
            vector<string> result2 = parse(S.substr(i + 1, n - 2 - i));
            for (string s1 : result1) {
                for (string s2 : result2) {
                    result.push_back("(" + s1 + ", " + s2 + ")");
                }
            }
        }
        return result;
    }
    
private:
    vector<string> parse(string s) {
        int n = s.size();
        vector<string> result;
        for (int i = 1; i < n; ++i) {
            string p1 = s.substr(0, i);
            string p2 = s.substr(i);
            if ((p1.size() == 1 || p1[0] != '0') && p2.back() != '0') {
                result.push_back(p1 + "." + p2);
            }
        }
        if (s.size() == 1 || s[0] != '0') {
            result.push_back(s);
        }
        return result;
    }
};
