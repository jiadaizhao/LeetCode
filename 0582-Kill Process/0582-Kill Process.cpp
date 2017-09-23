class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> table;
        int n = pid.size();
        for (int i = 0; i < n; ++i)
        {
            table[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> result;
        queue<int> Q;
        Q.push(kill);
        while (!Q.empty())
        {
            int parent = Q.front();
            result.push_back(parent);
            Q.pop();
            for (int child : table[parent])
            {
                Q.push(child);
            }
        }
        
        return result;
    }
};
