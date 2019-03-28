class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(1 + s2.size());
        vector<int> nextIndex(1 + s2.size());
        int j = 0, count = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if (j == s2.size()) {
                        j = 0;
                        ++count;
                    }
                }
            }
            
            repeatCount[k] = count;
            nextIndex[k] = j;
            for (int p = 0; p < k; ++p) {
                if (nextIndex[p] == j) {
                    int prefixCount = repeatCount[p];
                    int repeatedPattenCount = (n1 - p) / (k - p) * (repeatCount[k] - repeatCount[p]);
                    int suffixCount = repeatCount[p + (n1 - p) % (k - p)] - repeatCount[p];
                    return (prefixCount + repeatedPattenCount + suffixCount) / n2;
                }
            }
        }
        
        return count / n2;
    }
};
