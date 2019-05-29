class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int parent[26];
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
        
        for (string eq : equations) {
            if (eq[1] == '=') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                int px = findParent(parent, x);
                int py = findParent(parent, y);
                if (px != py) {
                    parent[px] = py;
                }
            }
        }
        
        for (string eq : equations) {
            if (eq[1] == '!') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                int px = findParent(parent, x);
                int py = findParent(parent, y);
                if (px == py) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    int findParent(int* parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};
