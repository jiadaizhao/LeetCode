class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        
        int i = 0;
        while (i < n) {
            int len = -1, start = i;
            while (i < n && len + words[i].size() + 1 <= maxWidth) {
                len += words[i++].size() + 1;
            }
            
            int space, padding;
            if (i == start + 1 || i == n) {
                space = 1;
                padding = 0;
            }
            else {
                space = (maxWidth - len) / (i - start - 1) + 1;
                padding = (maxWidth - len) % (i - start - 1);
            }
            
            string str = words[start];
            int count = i - start - 1;
            for (int k = 0; k < count; ++k) {
                str += string(space, ' ');
                if (padding > 0) {
                    str += " ";
                    --padding;
                }
                str += words[start + 1 + k];
            }
            
            if (maxWidth > str.size()) {
                str += string(maxWidth - str.size(), ' ');
            }
            
            result.push_back(str);
        }
        
        return result;
    }
};

class Solution2 {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result, curr;
        int num = 0;
        for (string word : words) {
            if (word.size() + curr.size() + num > maxWidth) {
                for (int i = 0; i < maxWidth - num; ++i) {
                    if (curr.size() > 1) {
                        curr[i % (curr.size() - 1)] += ' ';
                    }
                    else {
                        curr[0] += ' ';
                    }
                }
                string temp;
                for (string s : curr) {
                    temp += s;
                }
                result.push_back(temp);
                curr.clear();
                num = 0;
            }
            curr.push_back(word);
            num += word.size();
        }
        
        string temp = curr[0];
        for (int i = 1; i < curr.size(); ++i) {
            temp += ' ' + curr[i];
        }
        temp += string(maxWidth - temp.size(), ' ');
        result.push_back(temp);
        return result;
    }
};
