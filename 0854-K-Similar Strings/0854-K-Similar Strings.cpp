class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A == B) {
            return 0;
        }
        
        unordered_set<string> visited;
        queue<string> Q;
        Q.push(A);
        visited.insert(A);
        int count = 0;
        while (!Q.empty()) {
            ++count;
            int qs = Q.size();
            for (int k = 0; k < qs; ++k) {
                string s = Q.front();
                Q.pop();
                int i = 0;
                while (s[i] == B[i]) ++i;
                for (int j = i + 1; j < s.size(); ++j) {
                    if (s[j] == B[j] || s[i] != B[j]) {
                        continue;
                    }
                    swap(s[i], s[j]);
                    if (s == B) return count;
                    if (visited.insert(s).second) {
                        Q.push(s);
                    }                    
                    swap(s[i], s[j]);                    
                }
            }
        }
        return count;
    }
};
