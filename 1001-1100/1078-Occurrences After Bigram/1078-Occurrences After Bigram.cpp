class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        string pattern = first + ' ' + second + ' ';
        size_t index = text.find(pattern);
        while (index != string::npos) {
            int i = index + pattern.size(), j = i;
            while (j < text.size() && text[j] != ' ') {
                ++j;
            }
            result.push_back(text.substr(i, j - i));
            index = text.find(pattern, index + first.size() + 1);
        }
        return result;
    }
};
