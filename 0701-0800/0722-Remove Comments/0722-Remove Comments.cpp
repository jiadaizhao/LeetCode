class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        bool inBlock = false;
        string newLine;
        for (string s : source) {
            if (!inBlock) {
                newLine = "";
            }
            int i = 0;
            while (i < s.size()) {
                if (!inBlock) {
                    if (s.substr(i, 2) == "/*") {
                        inBlock = true;
                        i += 2;
                    }
                    else if (s.substr(i, 2) == "//") {
                        break;
                    }
                    else {
                        newLine += s[i++];
                    }
                }
                else if (s.substr(i, 2) == "*/") {
                    inBlock = false;
                    i += 2;
                }
                else {
                    i += 1;
                }
            } 
            
            if (newLine != "" && !inBlock) {
                result.push_back(newLine);
            }
        }
        
        return result;
    }
};
