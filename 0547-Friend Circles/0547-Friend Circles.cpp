class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = M.size();
        vector<int> parent(count);
        for (int i = 0; i < parent.size(); ++i)
        {
            parent[i] = i;
        }
        for (int i = 0; i < M.size(); ++i)
        {
            for (int j = i + 1; j < M[i].size(); ++j)
            {
                if (M[i][j] == 1)
                {
                    int pi = findParent(parent, i);
                    int pj = findParent(parent, j);
                    if (pi != pj)
                    {
                        --count;
                        parent[pi] = pj;
                    }
                }
            }
        }
        
        return count;
    }
    
private:
    int findParent(vector<int>& parent, int i)
    {
        while (parent[i] != i)
        {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        
        return i;
    }
};
