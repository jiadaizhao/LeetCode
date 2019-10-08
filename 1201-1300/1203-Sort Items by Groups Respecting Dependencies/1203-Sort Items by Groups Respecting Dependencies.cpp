class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int maxGroup = m;
        unordered_map<int, vector<int>> group2item;
        for (int i = 0; i < group.size(); ++i) {
            if (group[i] == -1) {
                group[i] = maxGroup++;
            }
            group2item[group[i]].push_back(i);
        }

        vector<int> itemDegree(n), groupDegree(maxGroup);
        vector<vector<int>> itemGraph(n), groupGraph(maxGroup);
        for (int j = 0; j < beforeItems.size(); ++j) {
            int toGroup = group[j];
            for (int i : beforeItems[j]) {
                int fromGroup = group[i];
                if (fromGroup == toGroup) {
                    itemGraph[i].push_back(j);
                    ++itemDegree[j];
                }
                else {
                    groupGraph[fromGroup].push_back(toGroup);
                    ++groupDegree[toGroup];
                }
            }
        }

        queue<int> Q;
        vector<int> groupResult;
        for (int i = 0; i < groupDegree.size(); ++i) {
            if (groupDegree[i] == 0) {
                Q.push(i);
                groupResult.push_back(i);
            }
        }
        
        while (!Q.empty()) {
            int from = Q.front();
            Q.pop();
            for (int to : groupGraph[from]) {
                if (--groupDegree[to] == 0) {
                    Q.push(to);
                    groupResult.push_back(to);
                }
            }
        }

        if (groupResult.size() != maxGroup) {
            return {};
        }

        vector<int> result;
        for (int g : groupResult) {
            int num = 0;
            for (int i : group2item[g]) {
                if (itemDegree[i] == 0) {
                    Q.push(i);
                    result.push_back(i);
                    ++num;
                }
            }

            while (!Q.empty()) {
                int from = Q.front();
                Q.pop();
                for (int to : itemGraph[from]) {
                    if (--itemDegree[to] == 0) {
                        Q.push(to);
                        result.push_back(to);
                        ++num;
                    }
                }
            }

            if (num != group2item[g].size()) {
                return {};
            }
        }

        return result;
    }
};
