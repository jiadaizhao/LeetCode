class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> left;
        unordered_set<int> remove;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                left.push_back(i);
            }
            else if (c == ')') {
                if (left.size()) {
                    left.pop_back();
                }
                else {
                    remove.insert(i);
                }
            }
        }
        
        remove.insert(left.begin(), left.end());
        
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (!remove.count(i)) {
                result += s[i];
            }
        }
        
        return result;
    }
};
