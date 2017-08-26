class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 2)
        {
            return {0, 1};
        }
        vector<int> degrees(n);
        unordered_map<int, unordered_set<int>> graph;
        for (auto edge : edges)
        {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
            ++degrees[edge.first];
            ++degrees[edge.second];
        }
        
        queue<int> Q;
        unordered_set<int> nodes;
        for (int i = 0; i < n; ++i)
        {
            nodes.insert(i);
        }
        for (int i = 0; i < n; ++i)
        {
            if (degrees[i] == 1)
            {
                --degrees[i];
                nodes.erase(i);
                Q.push(i);
            }
        }
        
        while (nodes.size() > 2)
        {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i)
            {
                int node = Q.front();
                Q.pop();
                for (int neighbor : graph[node])
                {
                    --degrees[neighbor];
                    if (degrees[neighbor] == 1)
                    {
                        --degrees[neighbor];
                        nodes.erase(neighbor);
                        Q.push(neighbor);
                    }
                }
            }
        }
        
        vector<int> result(nodes.begin(), nodes.end());
        return result;
    }
};
