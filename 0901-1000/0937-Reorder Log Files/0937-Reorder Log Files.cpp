class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp());
        return logs;
    }
    
private:
    struct cmp {
        bool operator() (string a, string b) {
            int i = a.find(' ');
            int j = b.find(' ');
            if (isalpha(a[i + 1])) {
                if (isalpha(b[j + 1])) {
                    if (a.substr(i + 1) == b.substr(j + 1)) {
                        return a.substr(0, i) < b.substr(0, j);
                    }
                    else {
                        return a.substr(i + 1) < b.substr(j + 1);
                    }
                }
                else {
                    return true;
                }
            }
            else {
                return false;
            }
        }
    };
};
