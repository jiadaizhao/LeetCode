class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<bool> letters(26);
        vector<unordered_set<int>> graph(26);
        string prev;
        for (string& word : words) {
            for (char c : word) {
                letters[c - 'a'] = true;
            }

            int i;
            int upper = min(prev.size(), word.size());
            for (i = 0; i < upper; ++i) {
                if (prev[i] != word[i]) {
                    graph[prev[i] - 'a'].insert(word[i] - 'a');
                    break;
                }
            }
            
            if (i == upper && prev.size() > word.size()) {
                return "";
            }
            
            prev = word;
        }
        
        vector<int> degrees(26);
        for (int i = 0; i < graph.size(); ++i) {
            for (int node : graph[i]) {
                ++degrees[node];
            }
        }
        
        queue<int> Q;
        string result;
        for (int i = 0; i < degrees.size(); ++i) {
            if (letters[i] && degrees[i] == 0) {
                Q.push(i);
                result += 'a' + i;
            }
        }
                
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            for (int node : graph[curr]) {
                if (--degrees[node] == 0) {
                    Q.push(node);
                    result += 'a' + node;
                }
            }
        }
        int count = accumulate(letters.begin(), letters.end(), 0);
        return result.size() == count ? result : "";
    }
};
