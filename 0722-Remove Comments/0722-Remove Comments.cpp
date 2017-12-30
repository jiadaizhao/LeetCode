class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        bool blockStart = false;
        for (string& s : source) {
            string path;
            bool newLine = true;
            bool currentLineBlockStart = false;
            for (int i = 0; i < s.size(); ++i) {
                if (blockStart) {
                    if (i < s.size() - 1 && s[i] == '*' && s[i + 1] == '/') {
                        blockStart = false;
                        if (!currentLineBlockStart) {
                            newLine = false;
                        }                        
                        ++i;
                    }
                }
                else {
                    if (i < s.size() - 1 && s[i] == '/' && s[i + 1] == '*') {
                        currentLineBlockStart = true;
                        blockStart = true;
                        ++i;
                    }
                    else if (i < s.size() - 1 && s[i] == '/' && s[i + 1] == '/') {
                        break;
                    }
                    else {
                        path += s[i];
                    }
                }
            }
            
            if (path.size() == 0) {
                continue;
            }
            
            if (newLine || result.size() == 0) {
                result.push_back(path);
            } 
            else {
                result.back() += path;
            }
        }
        
        return result;
    }
};
