class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet;
        for (string s : bank) {
            bankSet.insert(s);
        }
        
        queue<string> Q;
        unordered_set<string> visited;
        Q.push(start);
        visited.insert(start);
        int step = 0;
        vector<char> genes = {'A', 'C', 'G', 'T'};
        while (!Q.empty()) {
            ++step;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                string str = Q.front();
                Q.pop();
                for (int j = 0; j < str.size(); ++j) {
                    char c = str[j];
                    for (int k = 0; k < genes.size(); ++k) {
                        str[j] = genes[k];
                        if (!bankSet.count(str)) {
                            continue;
                        }
                        if (str == end) {
                            return step;
                        }
                        if (!visited.count(str)) {
                            Q.push(str);
                            visited.insert(str);
                        }
                    }
                    str[j] = c;
                }
            }
        }
        return -1;
    }
};
