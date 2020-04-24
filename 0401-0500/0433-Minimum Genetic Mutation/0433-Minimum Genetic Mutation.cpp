class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (find(bank.begin(), bank.end(), end) == bank.end()) {
            return -1;
        }
        unordered_map<string, vector<string>> table;
        int L = start.size();
        for (string gene : bank) {
            for (int i = 0; i < L; ++i) {
                table[gene.substr(0, i) + '*' + gene.substr(i + 1)].push_back(gene);
            }
        }
        
        int step = 0;
        unordered_set<string> visitedBegin{start}, visitedEnd{end};
        unordered_set<string> visited{start, end};
        while (!visitedBegin.empty() && !visitedEnd.empty()) {
            if (visitedBegin.size() > visitedEnd.size()) {
                swap(visitedBegin, visitedEnd);
            }
            
            ++step;
            unordered_set<string> temp;
            for (string g : visitedBegin) {
                for (int i = 0; i < L; ++i) {
                    string ng = g.substr(0, i) + '*' + g.substr(i + 1);
                    for (string gene : table[ng]) {
                        if (visitedEnd.count(gene)) {
                            return step;
                        }
                        if (!visited.count(gene)) {
                            temp.insert(gene);
                            visited.insert(gene);
                        }
                    }
                }
            }
            visitedBegin = move(temp);
        }
        
        return -1;
    }
};
