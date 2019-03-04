class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size(), count = n;
        vector<int> parents(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isSimilar(A[i], A[j])) {
                    int pa = findParent(parents, j);
                    int pb = findParent(parents, i);
                    if (pb != pa) {
                        parents[pb] = pa;
                        --count;
                    }                    
                }                
            }
        }
        
        return count;
    }
    
private:
    bool isSimilar(string& s, string& t) {
        int diff = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                ++diff;
                if (diff > 2) {
                    return false;
                }
            }
        }
        return true;
    }
    
    int findParent(vector<int>& parents, int i) {
        while (parents[i] != i) {
            parents[i] = parents[parents[i]];
            i = parents[i];
        }
        return i;
    } 
};
