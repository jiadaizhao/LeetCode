class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> parent(N);
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }
        
        sort(logs.begin(), logs.end());
        int count = N;
        for (auto log : logs) {
            int pa = findParent(parent, log[1]);
            int pb = findParent(parent, log[2]);
            if (pa != pb) {
                if (--count == 1) {
                    return log[0];
                }
                parent[pb] = pa;
            }
        }
        
        return -1;
    }
    
private:
    int findParent(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};
