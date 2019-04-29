class Solution {
public:
    string maskPII(string S) {
        int at = S.find('@');
        if (at == string::npos) {
            vector<string> country = {"", "+*-", "+**-", "+***-"};
            string str;
            for (char c : S) {
                if (isdigit(c)) {
                    str += c;
                }
            }
            return country[str.size() - 10] + "***-***-" + str.substr(str.size() - 4);
        }
        else {
            transform(S.begin(), S.end(), S.begin(), ::tolower);
            return S.substr(0, 1) + "*****" + S.substr(at - 1);
        }
    }
};
