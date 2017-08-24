class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<bool> letters(26);
        vector<unordered_set<int>> graph(26);
        string prev;
        for (string& word : words)
        {
            for (char c : word)
            {
                letters[c - 'a'] = true;
            }

            int i;
            for (i = 0; i < min(prev.size(), word.size()); ++i)
            {
                if (prev[i] != word[i])
                {
                    graph[prev[i] - 'a'].insert(word[i] - 'a');
                    break;
                }
            }
            
            if (i == min(prev.size(), word.size()) && prev.size() > word.size())
            {
                return "";
            }
            
            prev = word;
        }
        
        vector<int> degrees(26);
        for (int i = 0; i < graph.size(); ++i)
        {
            for (int node : graph[i])
            {
                ++degrees[node];
            }
        }
        
        queue<int> Q;
        string result;
        for (int i = 0; i < degrees.size(); ++i)
        {
            if (letters[i] && degrees[i] == 0)
            {
                Q.push(i);
                result += 'a' + i;
            }
        }
        
        int count = 0;
        for (int i = 0; i < letters.size(); ++i)
        {
            count += letters[i] ? 1 : 0;
        }
        while (!Q.empty())
        {
            int top = Q.front();
            Q.pop();
            for (int node : graph[top])
            {
                if (--degrees[node] == 0)
                {
                    Q.push(node);
                    result += 'a' + node;
                }
            }
        }
        
        if (result.size() == count)
        {
            return result;
        }
        else
        {
            return "";
        }
    }
};
