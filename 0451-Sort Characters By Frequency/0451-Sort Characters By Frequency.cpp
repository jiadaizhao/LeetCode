class Solution {
public:
    string frequencySort(string s) {
        vector<int> table(256);
        for (char c : s)
        {
            ++table[c];
        }
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < table.size(); ++i)
        {
            if (table[i])
            {
                pq.push({table[i], i});
            }
        }
        
        string result;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            result += string(p.first, p.second);
        }
        
        return result;
    }
};
