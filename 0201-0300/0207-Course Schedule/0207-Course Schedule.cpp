// BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p.second].insert(p.first);
        }
        
        vector<int> degrees(numCourses);
        for (auto g : graph) {
            for (int node : g) {
                ++degrees[node];
            }
        }
        
        queue<int> Q;
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) {
                Q.push(i);
            }
        }
        
        int count = 0;
        while (!Q.empty()) {
            ++count;
            int course = Q.front();
            Q.pop();
            for (int i : graph[course]) {
                if (--degrees[i] == 0) {
                    Q.push(i);
                }
            }
        }
        
        return count == numCourses;
    }
};

// DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p.second].insert(p.first);
        }
        
        vector<bool> visiting(numCourses);
        vector<bool> visited(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && dfsCycle(graph, i, visiting, visited)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfsCycle(vector<unordered_set<int>>& graph, int course, vector<bool>& visiting, vector<bool>& visited) {
        if (visited[course]) {
            return false;
        }
        
        visited[course] = visiting[course] = true;
        for (int i : graph[course]) {
            if (visiting[i] || dfsCycle(graph, i, visiting, visited)) {
                return true;
            }
        }
        
        return visiting[course] = false;
    }
};
