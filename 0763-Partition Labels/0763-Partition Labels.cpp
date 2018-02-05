class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26);
        for (int i = 0; i < S.size(); ++i) {
            last[S[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0, j = 0;
        for (int i = 0; i < S.size(); ++i) {
            j = max(j, last[S[i] - 'a']);
            if (j == i) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
