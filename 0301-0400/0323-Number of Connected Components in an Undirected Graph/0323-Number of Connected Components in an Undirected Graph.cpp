class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n <= 0) {
            return 0;
        }
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (auto p : edges) {
            int i = p.first;
            int j = p.second;
            int iparent = findParent(parent, i);
            int jparent = findParent(parent, j);
            if (iparent != jparent) {
                parent[iparent] = jparent;
                --n;
            }
        }
        
        return n;
    }
    
private:
    int findParent(vector<int>& parent, int pos) {
        while (parent[pos] != pos) {
            parent[pos] = parent[parent[pos]];
            pos = parent[pos];
        }
        
        return pos;
    }
};
