class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        bool validInput = false;
        vector<unordered_set<int>> graph(n);
        vector<int> degrees(n);
        for (auto& seq : seqs) {
            if (seq.size() == 0) {
                continue;
            }
            validInput = true;
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] > n || seq[i] < 1) {
                    return false;
                }
                
                if (i < seq.size() - 1 && seq[i + 1] > 0 && seq[i + 1] <= n && graph[seq[i] - 1].count(seq[i + 1] - 1) == 0) {
                    graph[seq[i] - 1].insert(seq[i + 1] - 1);
                    ++degrees[seq[i + 1] - 1];
                }
            }
        }
        
        if (!validInput) {
            return false;
        }
        
        queue<int> Q;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 0) {
                Q.push(i);
            }
        }
        
        while (Q.size() == 1) {
            int top = Q.front();
            Q.pop();
            ++count;
            if (org[count - 1] != top + 1) {
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
