class Solution {
public:
    string reformat(string s) {
        string a, d;
        for (char c : s) {
            if (isdigit(c)) {
                d += c;
            }
            else {
                a += c;
            }
        }
        
        if (d.size() > a.size() + 1 || a.size() > d.size() + 1) {
            return "";
        }
        
        if (a.size() <= d.size()) {
            swap(a, d);
        }
        string result;
        for (int i = 0; i < a.size() + d.size(); ++i) {
            if (i & 1) {
                result += d[i / 2];
            }
            else {
                result += a[i / 2];
            }
        }
        
        return result;
    }
};
