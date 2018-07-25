class Solution {
public:
    string toLowerCase(string str) {
        string result;
        for (char c : str) {
            if (c >= 'A' && c <= 'Z') {
                result += c - 'A' + 'a';
            }
            else {
                result += c;
            }
        }
        return result;
    }
};
