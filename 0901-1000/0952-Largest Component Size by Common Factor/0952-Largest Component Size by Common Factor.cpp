class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        vector<int> parent(A.size()), area(A.size(), 1);
        for (int i = 0; i < A.size(); ++i) {
            parent[i] = i;
        }
        
        int maxArea = 1;
        for (int i = 0; i < A.size(); ++i) {
            int d = 2, a = A[i];
            while (d * d <= a) {
                if (a % d == 0) {
                    while (a % d == 0) {
                        a /= d;
                    }
                    merge(parent, d, i, area, maxArea);
                }
                ++d;
            }
            if (a > 1) {
                merge(parent, a, i, area, maxArea);
            }
        }
        
        return maxArea;
    }
    
private:
    unordered_map<int, int> table;
    int findParent(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    void merge(vector<int>& parent, int d, int i, vector<int>& area, int& maxArea) {
        if (!table.count(d)) {
            table[d] = i;
        }
        else {
            int p1 = findParent(parent, table[d]);
            int p2 = findParent(parent, i);
            if (p1 != p2) {
                if (area[p1] < area[p2]) {
                    parent[p1] = p2;
                    area[p2] += area[p1];
                    maxArea = max(maxArea, area[p2]);
                }
                else {
                    parent[p2] = p1;
                    area[p1] += area[p2];
                    maxArea = max(maxArea, area[p1]);
                }
            }
        }
    }
};
