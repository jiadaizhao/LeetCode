class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = S.size();
        vector<int> table(n, -1);
        for (int i = 0; i < indexes.size(); ++i) {
            bool match = true;
            for (int j = 0; j < sources[i].size(); ++j) {
                if (indexes[i] + j >= S.size() || sources[i][j] != S[indexes[i] + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                table[indexes[i]] = i;
            }
        }
        
        string result;
        int i = 0;
        while (i < n) {
            if (table[i] != -1) {
                result += targets[table[i]];
                i += sources[table[i]].size();
            }
            else {
                result += S[i++];
            }
        }
        return result;
    }
};
