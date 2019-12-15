// BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degrees(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++degrees[p[0]];
        }

        queue<int> Q;        
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) {
                Q.push(i);
            }
        }
        
        int count = 0;
        while (!Q.empty()) {
            int i = Q.front();
            ++count;
            Q.pop();
            for (int j : graph[i]) {
                if (--degrees[j] == 0) {
                    Q.push(j);
                }
            }
        }
        
        return count == numCourses;
    }
};

// DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(graph, i, visited)) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int course, vector<int>& visited) {
        if (visited[course] == 1) {
            return true;
        }
        else if (visited[course] == 2) {
            return false;
        }
        
        visited[course] = 2;
        for (int i : graph[course]) {
            if (!dfs(graph, i, visited)) {
                return false;
            }
        }
        
        visited[course] = 1;
        return true;
    }
};
