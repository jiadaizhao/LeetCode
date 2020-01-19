class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) {
            return true;
        }
        unordered_set<int> visited;
        visited.insert(start);
        queue<int> Q;
        Q.push(start);
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            for (int next : {curr + arr[curr], curr - arr[curr]}) {
                if (next >= 0 && next < arr.size()) {
                    if (arr[next] == 0) {
                        return true;
                    }
                    if (!visited.count(next)) {
                        visited.insert(next);
                        Q.push(next);
                    }
                }
            }
        }
        return false;
    }
};
