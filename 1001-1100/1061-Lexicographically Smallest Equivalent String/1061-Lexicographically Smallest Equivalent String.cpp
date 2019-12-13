class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
        
        for (int i = 0; i < A.size(); ++i) {
            int p1 = findParent(parent, A[i] - 'a');
            int p2 = findParent(parent, B[i] - 'a');
            if (p1 < p2) {
                parent[p2] = p1;
            }
            else if (p1 > p2) {
                parent[p1] = p2;
            }
        }
        
        string result;
        for (char c : S) {
            result += 'a' + findParent(parent, c - 'a');
        }
        return result;
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
