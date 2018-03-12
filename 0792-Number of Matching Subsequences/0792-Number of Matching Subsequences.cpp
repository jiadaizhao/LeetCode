class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> table(26);
        for (int i = 0; i < S.size(); ++i) {
            table[S[i] - 'a'].push_back(i);
        }
        
        int count = 0;
        for (string word : words) {
            int index = -1;
            bool flag = true;
            for (char c : word) {
                auto it = upper_bound(table[c - 'a'].begin(), table[c - 'a'].end(), index);
                if (it == table[c - 'a'].end()) {
                    flag = false;
                    break;
                }
                else {
                    index = *it;
                }                
            }
            if (flag) {
                ++count;
            }
        }
        return count;
    }
};
