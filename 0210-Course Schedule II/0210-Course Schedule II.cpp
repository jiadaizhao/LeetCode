// BFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto& p : prerequisites)
        {
            graph[p.second].insert(p.first);
        }
        
        vector<int> degrees(numCourses);
        for (auto g : graph)
        {
            for (int node : g)
            {
                ++degrees[node];
            }
        }
        
        queue<int> Q;
        vector<int> result;
        for (int i = 0; i < numCourses; ++i)
        {
            if (degrees[i] == 0)
            {
                Q.push(i);
            }
        }
        
        while (!Q.empty())
        {
            int course = Q.front();
            result.push_back(course);
            Q.pop();
            for (int i : graph[course])
            {
                if (--degrees[i] == 0)
                {
                    Q.push(i);
                }
            }
        }
        
        if (result.size() == numCourses)
        {
            return result;
        }
        else
        {
            return vector<int>();
        }
    }
};

// DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto& p : prerequisites)
        {
            graph[p.second].insert(p.first);
        }
        
        vector<bool> visiting(numCourses);
        vector<bool> visited(numCourses);
        vector<int> result;
        for (int i = 0; i < numCourses; ++i)
        {
            if (!visited[i] && dfsCycle(graph, i, visiting, visited, result))
            {
                return {};
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool dfsCycle(vector<unordered_set<int>>& graph, int course, vector<bool>& visiting, vector<bool>& visited, vector<int>& result)
    {
        if (visited[course])
        {
            return false;
        }
        
        visited[course] = visiting[course] = true;
        for (int i : graph[course])
        {
            if (visiting[i] || dfsCycle(graph, i, visiting, visited, result))
            {
                return true;
            }
        }
        
        result.push_back(course);
        return visiting[course] = false;
    }
};