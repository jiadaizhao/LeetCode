class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        bool validInput = false;
        vector<unordered_set<int>> graph(n + 1);
        vector<int> degrees(n + 1);
        for (auto& seq : seqs) {
            if (seq.size() == 0) {
                continue;
            }
            validInput = true;
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] > n || seq[i] < 1) {
                    return false;
                }
                
                if (i < seq.size() - 1 && seq[i + 1] > 0 && seq[i + 1] <= n && !graph[seq[i]].count(seq[i + 1])) {
                    graph[seq[i]].insert(seq[i + 1]);
                    ++degrees[seq[i + 1]];
                }
            }
        }
        
        if (!validInput) {
            return false;
        }
        
        queue<int> Q;        
        for (int i = 1; i <= n; ++i) {
            if (degrees[i] == 0) {
                Q.push(i);
            }
        }
        
        int count = 0;
        while (Q.size() == 1) {
            int top = Q.front();
            Q.pop();
            if (org[count++] != top) {
                return false;
            }
            for (int i : graph[top]) {
                if (--degrees[i] == 0) {
                    Q.push(i);
                }
            }
        }
        
        return count == n;
    }
};
