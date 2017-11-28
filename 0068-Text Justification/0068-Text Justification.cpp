class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();        
        if (maxWidth <= 0) {
            for (int i = 0; i < n; ++i) {
                result.push_back("");
            }
            return result;
        }
        
        int j;
        for (int i = 0; i < n; i = j) {
            j = i;
            int len = -1;
            while (j < n && len + words[j].size() + 1 <= maxWidth) {
                len += words[j].size() + 1;
                ++j;
            }
            
            int space, padding;
            if (j == i + 1 || j == n) {
                space = 1;
                padding = 0;
            }
            else {
                space = (maxWidth - len) / (j - i - 1) + 1;
                padding = (maxWidth - len) % (j - i - 1);
            }
            
            string str = words[i];
            int count = j - i - 1;
            for (int k = 0; k < count; ++k) {
                str += string(space, ' ');
                if (padding > 0) {
                    str += " ";
                    --padding;
                }
                str += words[i + 1 + k];
            }
            
            if (maxWidth > str.size()) {
                str += string(maxWidth - str.size(), ' ');
            }
            
            result.push_back(str);
        }
        
        return result;
    }
};
