class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> result;
        if (m <= 0 || n <= 0)
        {
            result;
        }
        
        vector<int> parent(m * n, -1);
        int count = 0;
        vector<int> deltaX = {-1, 1, 0, 0};
        vector<int> deltaY = {0, 0, -1, 1};
        for (auto& p : positions)
        {
            int i = p.first;
            int j = p.second;
            int pos = i * n + j;
            if (parent[pos] == -1)
            {
                ++count;
                parent[pos] = pos;
                for (int k = 0; k < deltaX.size(); ++k)
                {
                    int x = i + deltaX[k];
                    int y = j + deltaY[k];
                    int npos = x * n + y;
                    if (x < 0 || x >= m || y < 0 || y >= n || parent[npos] == -1)
                    {
                        continue;
                    }
                    
                    int posParent = findParent(parent, pos);
                    int nposParent = findParent(parent, npos);
                    if (nposParent != posParent)
                    {
                        --count;
                        parent[posParent] = nposParent;
                    }
                }
            }

            result.push_back(count);
        }
        
        return result;
    }
    
private:
    int findParent(vector<int>& parent, int pos)
    {
        while (parent[pos] != pos)
        {
            parent[pos] = parent[parent[pos]];
            pos = parent[pos];
        }
        
        return pos;
    }
};
