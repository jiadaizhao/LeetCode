// BFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degrees(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++degrees[p[0]];
        }
        
        queue<int> Q;
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) {
                Q.push(i);
                result.push_back(i);
            }
        }
        
        while (!Q.empty()) {
            int course = Q.front();
            Q.pop();
            for (int i : graph[course]) {
                if (--degrees[i] == 0) {
                    Q.push(i);
                    result.push_back(i);
                }
            }
        }
        
        return result.size() == numCourses ? result : vector<int>();
    }
};

// DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses);
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(graph, i, visited, result)) {
                return {};
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int course, vector<int>& visited, vector<int>& result) {
        if (visited[course] == 1) {
            return true;
        }
        else if (visited[course] == 2) {
            return false;
        }
        
        visited[course] = 2;
        for (int i : graph[course]) {
            if (!dfs(graph, i, visited, result)) {
                return false;
            }
        }
        
        result.push_back(course);
        visited[course] = 1;
        return true;
    }
};
