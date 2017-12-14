class Solution {
public:
    bool isValid(string code) {
        stack<string> St;
        int i = 0;
        while (i < code.size()) {
            if (i > 0 && St.empty()) {
                return false;
            }
            
            if (code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                i = code.find("]]>", j);
                if (i == string::npos) {
                    return false;
                }
                i += 3;
            }
            else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                i = code.find(">", j);
                if (i == string::npos) {
                    return false;
                }
                string s = code.substr(j, i - j);
                if (St.empty() || s != St.top()) {
                    return false;
                }
                St.pop();
                ++i;
            }
            else if (code.substr(i, 1) == "<") {
                int j = i + 1;
                i = code.find('>', j);
                if (i == string::npos || i == j || i - j > 9) {
                    return false;
                }
                for (int k = j; k < i; ++k) {
                    if (!isupper(code[k])) {
                        return false;
                    }
                }
                string s = code.substr(j, i - j);
                St.push(s);
                ++i;
            }
            else {
                ++i;
            }
        }
        
        return St.empty();
    }
};
