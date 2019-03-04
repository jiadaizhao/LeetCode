class Solution {
public:
    string maskPII(string S) {
        int at = S.find('@');
        if (at == string::npos) {
            vector<string> country = {"", "+*-", "+**-", "+***-"};
            S = regex_replace(S, regex("[^0-9]"), "");
            return country[S.size() - 10] + "***-***-" + S.substr(S.size() - 4);
        }
        else {
            transform(S.begin(), S.end(), S.begin(), ::tolower);
            return S.substr(0, 1) + "*****" + S.substr(at - 1);
        }
    }
};
