class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> graph(1 + N);
        vector<int> degrees(1 + N);
        for (auto r : relations) {
            graph[r[0]].push_back(r[1]);
            ++degrees[r[1]];
        }
        
        queue<int> Q;
        for (int i = 1; i <= N; ++i) {
            if (degrees[i] == 0) {
                Q.push(i);
            }
        }
        int course = 0, semester = 0;
        while (!Q.empty()) {
            ++semester;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int curr = Q.front();
                Q.pop();
                ++course;
                for (int n : graph[curr]) {
                    if (--degrees[n] == 0) {
                        Q.push(n);
                    }
                }
            }
        }
        
        return course == N ? semester : -1;
    }
};
