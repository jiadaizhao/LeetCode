class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        vector<bool> bold(n);
        for (string word : words) {
            int m = word.size();
            for (int i = 0; i < n - m + 1; ++i) {
                if (word == S.substr(i, m)) {
                    for (int j = i; j < i + m; ++j) {
                        bold[j] = true;
                    }
                }
            }
        }
        
        string result;
        int i = 0;
        while (i < n) {
            if (bold[i]) {
                result += "<b>";
                while (i < n && bold[i]) {
                    result += S[i++];
                }
                result += "</b>";
            }
            else {
                result += S[i++];
            }
        }
        return result;  
    }
};
